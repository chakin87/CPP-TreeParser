/* to use this, 
     - write a form that calls this program with 'action=' in the <form> tag
     - call getPostData() 
     - use getField(string) to access form information 

*/
#include <iostream>
#include <cstdlib>
#include "htmlform.h"
#include "binarysearchtree.h"
void printProgram(string);   /// print the program in HTML
void parseProgram(std::vector<std::string> str, BinarySearchTree& b);
void printProgramTree(BinarySearchTree& b);

using namespace std;

int main()
{
  /// complete the http header
  cout << "Content-type: text/html\n\n";

  /// build a form object
  HTMLform steps;
  steps.getPostData();

  /// Show the debugging
  cout << "Queue Parser Lab startup" << endl;
  steps.debug();

  

  /// the entire programs
  string program = steps.getField("program");
  
  printProgram(program);
  
  //The next line is for you to complete
  //parseProgram(program);

  std::string ii;
  std::cin >> ii;
 // while (1) { std::cin.get(); }

  return 0;
}

void printProgram(string program)
{
	BinarySearchTree b;
  /// a single line
  string line;
  /// for counting the lines
  int count = 0;
  /// where the newline is (for peeling off a line)
  int pos;

  program += " \n";

  std::vector<std::string> str,method;

  while ( string::npos != (pos = program.find("\n") ) ){
      line = program.substr(0, pos);    /// before the newline
	  
      program = program.substr(pos+1);  /// after the newline
      /// there might newline characters at the end of line
      if (line[pos] < '0') line.erase(pos-1);
      
      
      /// here's where you need to process 'line'
      /// this routine just prints it.
	  str.push_back(line.substr(0, line.find("\n")));

  }
  std::cout << "8before parse" << "<br />";
  parseProgram(str, b);
  printProgramTree(b);
  /*
  std::string strCheck;
  std::string strNum ="";
  std::string strParser;
  std::string strData;
  std::string strMethod;
  int iNum;
  

	strMethod = str[str.size()-1];

  for (int i = 0; i < str.size()-1; ++i) {
	  strNum = "";
	  strCheck = str[i].substr(0, str[i].find(" "));

	  strParser = str[i].substr(0, str[i].find(","));

	  if (strParser.length() == 9) {
		  strNum += strParser.at(7);
		  strNum += strParser.at(8);
		 strData = str[i].substr(11, str[i].find("\n"));
	  }
	  else if (strParser.length() == 8) {
		  strNum += strParser.at(7);
		  strData = str[i].substr(10, str[i].find("\n"));
	  }

	  iNum = atoi(strNum.c_str());
	  if (strCheck == "INSERT") {
		b.Insert(iNum, strData);
	  }
	  else {
		  std::cout << "YOU MUST USE INSERT!!! :( " << "<br / >";
	  }
	///  std::cout << "in for loop at the end!!!"<< "<br />";
  }


  if (strMethod == "PREORDER") {
	  std::cout << "<table border='1'>";
	  b.preorderPrint();	
	  std::cout << "</table>";
  }
  else if (strMethod == "INORDER") {
	  std::cout << "<table border='1'>";
	  b.inorderPrint();
	  std::cout << "</table>";
  }
  else if (strMethod == "POSTORDER") {
	  std::cout << "<table border='1'>";
	  b.postorderPrint();
	  std::cout << "</table>";
  }
  */


}


void parseProgram(std::vector<std::string> str, BinarySearchTree& b){


	std::string strCheck;
	std::string strNum = "";
	std::string strParser;
	std::string strData;
	std::string strMethod;
	int iNum;


	strMethod = str[str.size() - 1];

	for (int i = 0; i < str.size() - 1; ++i) {
		strNum = "";
		strCheck = str[i].substr(0, str[i].find(" "));

		strParser = str[i].substr(0, str[i].find(","));

		if (strParser.length() == 9) {
			strNum += strParser.at(7);
			strNum += strParser.at(8);
			strData = str[i].substr(11, str[i].find("\n"));
		}
		else if (strParser.length() == 8) {
			strNum += strParser.at(7);
			strData = str[i].substr(10, str[i].find("\n"));
		}

		iNum = atoi(strNum.c_str());
		if (strCheck == "INSERT") {
			b.Insert(iNum, strData);
		}
		else {
			std::cout << "YOU MUST USE INSERT!!! :( " << "<br / >";
		}
		///  std::cout << "in for loop at the end!!!"<< "<br />";
	}


	if (strMethod == "PREORDER") {
		std::cout << "<table border='1'>";
		b.preorderPrint();
		std::cout << "</table>";
	}
	else if (strMethod == "INORDER") {
		std::cout << "<table border='1'>";
		b.inorderPrint();
		std::cout << "</table>";
	}
	else if (strMethod == "POSTORDER") {
		std::cout << "<table border='1'>";
		b.postorderPrint();
		std::cout << "</table>";
	}

}


void printProgramTree(BinarySearchTree& b) {
	b.printBTbylevel2();
}