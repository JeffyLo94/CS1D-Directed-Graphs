/*******************************************************************************
*	AUTHOR	   : Jeffrey Lo
*	ASSIGN #10 : Undirected Graphs
*	CLASS      : CS1D
*	SECTION    : 5-9p T-Th
*	DUE DATE   : 3/10/2015
*******************************************************************************/
#ifndef ASSIGNMENTS_H_
#define ASSIGNMENTS_H_

#include <iomanip>
#include <cstring>
#include <iostream>
#include <limits>
using namespace std;

// N A M E S P A C E
namespace JeffreyLo
{
    // G L O B A L   C O N S T A N T S
    /**************************************************************************
     * Used for OutputHeader
     * -----------------------------------------------------------------------
     * NAME		-	Programmer Name
     * CLASS	-	Class Name
     * Section	-	Section Time
     * AS_NUM	-	Assignment Number
     * AS_NAME	-	Assignment Name
     * AS_TYPE	-	Assignment Type
     **************************************************************************/
    const string NAME 		= "Jeffrey Lo";
    const string CLASS 		= "CS1D";
    const string SECTION	= "T-Th 5:30p - 9:20p";
    const int    AS_NUM 	= 10;
    const string AS_NAME	= "Undirected Graph";
    const char   AS_TYPE	= 'A';
}

// P R O T O T Y P E S
/******************************************************************************
 * FUNCTION OutputHeader
 * ----------------------------------------------------------------------------
 *		This function will output the header information to the console
 ******************************************************************************/
void OutputHeader(const string NAME,	// Holds the value of the name(s)
                                        // being output
    const string CLASS,     // Holds the class
    const string SECTION,   // Holds the time and day of class
    const int LAB_NUM,      // Holds the lab number
    const string LAB_NAME,  // Holds the lab name
    char asType,            // Either L(lab), or A(assign)
    ostream& out);          // Used for output

/*******************************************************************************
 * FUNCTION OutputHeader
 * ----------------------------------------------------------------------------
 * This function will output the header information to the console
 * ----------------------------------------------------------------------------
 * PRE-CONDITIONS
 * 		Literals are passed as arguments through the parameter list.
 * 		This are given their values in the calling of this function in
 * 		main.
 *
 * 	POST-CONDITIONS
 * 		Since this function is a void function there is no return value.
 * 		However, it does output c-string literals.
 ******************************************************************************/

void OutputHeader(const string NAME,	// Holds the value of the name(s)
                                        // being output
                const string CLASS,	// Holds the class
                const string SECTION,   // Holds the time and day of class
                const int LAB_NUM,      // Holds the lab number
                const string LAB_NAME,  // Holds the lab name
                char asType,			// Either L(lab), or A(assign)
                ostream& out)			// Used for output
{
	out << left;
	out << "**************************************************\n";
	out << "* Programmed by : " << NAME << "\n";
	out << "* " << setw(14) << "Student ID" << ": 374780 & 364919";
	out << "\n* " << setw(14) << CLASS << ": " << SECTION;
	if (toupper(asType) == 'L')
	{
		out << "\n* LAB #" << setw(9);
	}
	else
	{
		out << "\n* ASSIGNMENT #" << setw(2);
	}
	out << LAB_NUM << ": " << LAB_NAME;
	out << "\n**************************************************\n";

}
#endif /* ASSIGNMENTS_H_ */