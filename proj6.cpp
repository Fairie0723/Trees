

/**********************************
 This is the driver file
 for the wordtree.h file. It runs the program
 and reads the files and instantiates objects.
**********************************/

#include <iostream>
#include <fstream>
#include "wordtree.h"
#include <vector>

/**************************************
Function: split(string&, char, std::vector<std::string>&
Input: string, char, string
Output: takes the words in the fle and splits them
***************************************/
void split(const std::string& s, char c, std::vector<std::string>& v) {
    std::string::size_type i = 0;
    std::string::size_type j = s.find(c);

    while (j != std::string::npos) {
        v.push_back(s.substr(i, j-i));
        i = ++j;
        j = s.find(c, j);

        if (j == std::string::npos)
            v.push_back(s.substr(i, s.length()));
    }
}
/**************************************
Function: main()
Input: None
Output: Reads in the files from the text
        and instantiates the objects.
***************************************/
int main() {

    std::ifstream inFile ("input.txt"); //Opens and reads the text file named input.txt

    WordTree word; //Instantiates the WordTree object
    std::string add_word;
    std::vector<std::string>each_word;
    int intNum = 0;
    char  letter;
    std::string wordFind;
    getline(inFile, add_word);
    split(add_word, ' ', each_word);
    std::ifstream inFile2("queries.txt"); //Opens the queries.txt file and invokes each query, as the file is read.


    std::cout << "Word tree built and loaded" << std::endl;
    std::cout << "\nFinding all words with " <<  intNum << " or more occurrences:" << std::endl;

    //builds the word tree from the file by invoking the
    //addWord function
    for (auto & i : each_word){
        word.addWord(i);
    }
    //reads in the queries.txt file
    while(inFile2 >> letter){
        if (letter == 'C'){
            inFile2 >> intNum;
            word.getCounts(intNum);
            std::cout << std::endl;
        }
        if(letter == 'F'){
            inFile2 >> wordFind;
            word.findWord(wordFind);
            std::cout << std::endl;
        }
    }

    inFile.close();
    inFile2.close();

    return 0;
}

