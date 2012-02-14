#!/usr/bin/perl
#  IBM_PROLOG_BEGIN_TAG
#  This is an automatically generated prolog.
#
#  $Source: src/usr/hwpf/fapi/fapiParseAttributeInfo.pl $
#
#  IBM CONFIDENTIAL
#
#  COPYRIGHT International Business Machines Corp. 2011
#
#  p1
#
#  Object Code Only (OCO) source materials
#  Licensed Internal Code Source Materials
#  IBM HostBoot Licensed Internal Code
#
#  The source code for this program is not published or other-
#  wise divested of its trade secrets, irrespective of what has
#  been deposited with the U.S. Copyright Office.
#
#  Origin: 30
#
#  IBM_PROLOG_END
#
# Purpose:  This perl script will parse HWP Attribute XML files
# and add attribute information to a file called fapiAttributeIds.H
#
# Author: CamVan Nguyen
# Last Updated: 06/23/2011
#
# Version: 1.0
#
# Change Log **********************************************************
#
#  Flag  Track#    Userid    Date      Description
#  ----  --------  --------  --------  -----------
#                  camvanng  06/03/11  Created
#                  mjjones   06/06/11  Minor updates for integration
#                  mjjones   06/10/11  Added "use strict;"
#                  mjjones   06/23/11  Parse more info
#                  mjjones   07/05/11  Take output dir as parameter
#                  mjjones   09/06/11  Remove string/defaultVal support 
#                  mjjones   10/07/11  Create fapiAttributeService.C
#                  mjjones   10/17/11  Support enums with values
#                  mjjones   10/18/11  Support multiple attr files and
#                                      multi-line descriptions
#                  camvanng  10/20/11  Changed i_pTarget to "const" ptr
#                  camvanng  11/09/11  Prepend "ENUM_" to attribute
#                                      enums
#                  mjjones   11/15/11  Move gen of fapiAttributeService.C
#                                      to a different file
#                  mjjones   12/16/11  Generate fapiAttributePlatCheck.H
#                                      Generate fapiAttributesSupported.html
#                  mjjones   02/08/12  Handle attribute files with 1 entry
#
# End Change Log ******************************************************

use strict;

#------------------------------------------------------------------------------
# Print Command Line Help
#------------------------------------------------------------------------------
my $numArgs = $#ARGV + 1;
if ($numArgs < 2)
{
    print ("Usage: fapiParseAttributeInfo.pl <output dir> <attr-xml-file1> [<attr-xml-file2> ...]\n");
    print ("  This perl script will parse attribute XML files and create the following files:\n");
    print ("  - fapiAttributeIds.H.          Contains IDs, type, value enums and other information\n");
    print ("  - fapiAttributePlatCheck.H.    Contains compile time checks that all attributes are\n");
    print ("                                 handled by the platform\n");
    print ("  - fapiAttributesSupported.html Contains the HWPF attributes supported\n");
    exit(1);
}

#------------------------------------------------------------------------------
# Specify perl modules to use
#------------------------------------------------------------------------------
use XML::Simple;
my $xml = new XML::Simple (KeyAttr=>[]);

# Uncomment to enable debug output
#use Data::Dumper;

#------------------------------------------------------------------------------
# Open output files for writing
#------------------------------------------------------------------------------
my $aiFile = $ARGV[0];
$aiFile .= "/";
$aiFile .= "fapiAttributeIds.H";
open(AIFILE, ">", $aiFile);

my $acFile = $ARGV[0];
$acFile .= "/";
$acFile .= "fapiAttributePlatCheck.H";
open(ACFILE, ">", $acFile);

my $asFile = $ARGV[0];
$asFile .= "/";
$asFile .= "fapiAttributesSupported.html";
open(ASFILE, ">", $asFile);

#------------------------------------------------------------------------------
# Print Start of file information to fapiAttributeIds.H
#------------------------------------------------------------------------------
print AIFILE "// fapiAttributeIds.H\n";
print AIFILE "// This file is generated by perl script fapiParseAttributeInfo.pl\n\n";
print AIFILE "#ifndef FAPIATTRIBUTEIDS_H_\n";
print AIFILE "#define FAPIATTRIBUTEIDS_H_\n\n";
print AIFILE "namespace fapi\n";
print AIFILE "{\n\n";
print AIFILE "\/**\n";
print AIFILE " * \@brief Enumeration of attribute IDs\n";
print AIFILE " *\/\n";
print AIFILE "enum AttributeId\n{\n";

#------------------------------------------------------------------------------
# Print Start of file information to fapiAttributePlatCheck.H
#------------------------------------------------------------------------------
print ACFILE "// fapiAttributePlatCheck.H\n";
print ACFILE "// This file is generated by perl script fapiParseAttributeInfo.pl\n";
print ACFILE "// A platform can include it to ensure that it handles all HWPF\n";
print ACFILE "// attributes\n\n";
print ACFILE "#ifndef FAPIATTRIBUTEPLATCHECK_H_\n";
print ACFILE "#define FAPIATTRIBUTEPLATCHECK_H_\n\n";

#------------------------------------------------------------------------------
# Print Start of file information to fapiAttributesSupported.html
#------------------------------------------------------------------------------
print ASFILE "<html>\n";
print ASFILE "<body>\n\n";
print ASFILE "<!-- fapiAttributesSupported.html -->\n";
print ASFILE "<!-- This file is generated by perl script fapiParseAttributeInfo.pl -->\n";
print ASFILE "<!-- It lists all HWPF attributes supported -->\n\n";
print ASFILE "<h4>HWPF Attributes supported by this build.</h4>\n";
print ASFILE "<table border=\"4\">\n";
print ASFILE "<tr><th>Attribute ID</th><th>Attribute Description</th></tr>";

#------------------------------------------------------------------------------
# Element names
#------------------------------------------------------------------------------
my $attribute = 'attribute';

#------------------------------------------------------------------------------
# For each XML file
#------------------------------------------------------------------------------
foreach my $argnum (1 .. $#ARGV)
{
    my $infile = $ARGV[$argnum];

    # read XML file. The ForceArray option ensures that there is an array of
    # attributes even if there is only one attribute in the file
    my $attributes = $xml->XMLin($infile, ForceArray => [$attribute]);

    # Uncomment to get debug output of all attributes
    #print "\nFile: ", $infile, "\n", Dumper($attributes), "\n";

    #--------------------------------------------------------------------------
    # For each Attribute
    #--------------------------------------------------------------------------
    foreach my $attr (@{$attributes->{attribute}})
    {
        #----------------------------------------------------------------------
        # Print the AttributeId to fapiAttributeIds.H
        #----------------------------------------------------------------------
        if (! exists $attr->{id})
        {
            print ("fapiParseAttributeInfo.pl ERROR. Att 'id' missing\n");
            exit(1);
        }

        print AIFILE "    $attr->{id},\n";
    };
}

#------------------------------------------------------------------------------
# Print AttributeId enumeration end to fapiAttributeIds.H
#------------------------------------------------------------------------------
print AIFILE "};\n\n";

#------------------------------------------------------------------------------
# Print Attribute Information comment to fapiAttributeIds.H
#------------------------------------------------------------------------------
print AIFILE "\/**\n";
print AIFILE " * \@brief Attribute Information\n";
print AIFILE " *\/\n";

#------------------------------------------------------------------------------
# For each XML file
#------------------------------------------------------------------------------
foreach my $argnum (1 .. $#ARGV)
{
    my $infile = $ARGV[$argnum];

    # read XML file. The ForceArray option ensures that there is an array of
    # attributes even if there is only one attribute in the file
    my $attributes = $xml->XMLin($infile, ForceArray => [$attribute]);

    #--------------------------------------------------------------------------
    # For each Attribute
    #--------------------------------------------------------------------------
    my $attCount = 0;

    foreach my $attr (@{$attributes->{attribute}})
    {
        #----------------------------------------------------------------------
        # Print a comment with the attribute ID fapiAttributeIds.H
        #----------------------------------------------------------------------
        print AIFILE "/* $attr->{id} */\n";

        #----------------------------------------------------------------------
        # Print the AttributeId and description to fapiAttributesSupported.html
        #----------------------------------------------------------------------
        if (! exists $attr->{description})
        {
            print ("fapiParseAttributeInfo.pl ERROR. Att 'description' missing\n");
            exit(1);
        }

        print ASFILE "<tr>\n";
        print ASFILE "  <td>$attr->{id}</td>\n";
        print ASFILE "  <td>$attr->{description}</td>\n";
        print ASFILE "</tr>\n";

        #----------------------------------------------------------------------
        # Figure out the attribute array dimensions (if array)
        #----------------------------------------------------------------------
        my $arrayDimensions = "";
        my $numArrayDimensions = 0;
        if ($attr->{array})
        {
            # Figure out the array dimensions

            # Remove leading whitespace
            my $dimText = $attr->{array};
            $dimText =~ s/^\s+//;

            # Split on commas or whitespace
            my @vals = split(/\s*,\s*|\s+/, $dimText);

            foreach my $val (@vals)
            {
                $arrayDimensions .= "[${val}]";
                $numArrayDimensions++;
            }
        }

        #----------------------------------------------------------------------
        # Print the typedef for each attribute's val type to fapiAttributeIds.H
        #----------------------------------------------------------------------
        if (! exists $attr->{valueType})
        {
            print ("fapiParseAttributeInfo.pl ERROR. Att 'valueType' missing\n");
            exit(1);
        }

        if ($attr->{valueType} eq 'uint8')
        {
            print AIFILE "typedef uint8_t $attr->{id}_Type$arrayDimensions;\n";
        }
        elsif ($attr->{valueType} eq 'uint32')
        {
            print AIFILE "typedef uint32_t $attr->{id}_Type$arrayDimensions;\n";
        }
        elsif ($attr->{valueType} eq 'uint64')
        {
            print AIFILE "typedef uint64_t $attr->{id}_Type$arrayDimensions;\n";
        }
        else
        {
            print ("fapiParseAttributeInfo.pl ERROR. valueType not recognized: ");
            print $attr->{valueType}, "\n";
            exit(1);
        }

        #----------------------------------------------------------------------
        # Print if the platform initializes the value to fapiAttributeIds.H
        #----------------------------------------------------------------------
        if (exists $attr->{platInit})
        {
            print AIFILE "#define $attr->{id}_PLATINIT true\n"
        }
        else
        {
            print AIFILE "#define $attr->{id}_PLATINIT false\n"
        }

        #----------------------------------------------------------------------
        # Print the value enumeration (if specified) to fapiAttributeIds.H
        #----------------------------------------------------------------------
        if (exists $attr->{enum})
        {
            print AIFILE "enum $attr->{id}_Enum\n{\n";

            # Values must be separated by commas to allow for values to be
            # specified: <enum>VAL_A = 3, VAL_B = 5, VAL_C = 0x23</enum>
            my @vals = split(',', $attr->{enum});

            foreach my $val (@vals)
            {
                # Remove leading spaces
                $val =~ s/^\s+//; 
                print AIFILE "    ENUM_$attr->{id}_${val},\n";
            }

            print AIFILE "};\n";
        }

        #----------------------------------------------------------------------
        # If the attribute is read-only then define the _SETMACRO to something
        # that will cause a compile failure if a set is attempted
        #----------------------------------------------------------------------
        if (! exists $attr->{writeable})
        {
            print AIFILE "#define $attr->{id}_SETMACRO ATTRIBUTE_NOT_WRITABLE\n";
        }

        #----------------------------------------------------------------------
        # Print the platform attribute checks to fapiAttributePlatCheck.H
        #----------------------------------------------------------------------
        if (exists $attr->{writeable})
        {
            print ACFILE "#ifndef $attr->{id}_SETMACRO\n";
            print ACFILE "#error Platform does not support set of HWPF attr $attr->{id}\n";
            print ACFILE "#endif\n";
        }

        print ACFILE "#ifndef $attr->{id}_GETMACRO\n";
        print ACFILE "#error Platform does not support get of HWPF attr $attr->{id}\n";
        print ACFILE "#endif\n\n";

        #----------------------------------------------------------------------
        # Print newline between each attribute's info to fapiAttributeIds.H
        #----------------------------------------------------------------------
        print AIFILE "\n";
    };
}

#------------------------------------------------------------------------------
# Print End of file information to fapiAttributeIds.H
#------------------------------------------------------------------------------
print AIFILE "}\n\n";
print AIFILE "#endif\n";

#------------------------------------------------------------------------------
# Print End of file information to fapiAttributePlatCheck.H
#------------------------------------------------------------------------------
print ACFILE "#endif\n";

#------------------------------------------------------------------------------
# Print End of file information to fapiAttributesSupported.html
#------------------------------------------------------------------------------
print ASFILE "</table>\n\n";
print ASFILE "</body>\n";
print ASFILE "</html>\n";

#------------------------------------------------------------------------------
# Close output files
#------------------------------------------------------------------------------
close(AIFILE);
close(ACFILE);
close(ASFILE);

