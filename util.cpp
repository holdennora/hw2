#include <iostream>
#include <sstream>
#include <cctype>
#include <algorithm>
#include "util.h"

using namespace std;
std::string convToLower(std::string src)
{
    std::transform(src.begin(), src.end(), src.begin(), ::tolower);
    return src;
}

/** Complete the code to convert a string containing a rawWord
    to a set of words based on the criteria given in the assignment **/
std::set<std::string> parseStringToWords(string rawWords)
{
    std::set<std::string> wordSet;
    rawWords = convToLower(rawWords);
    rawWords = trim(rawWords);
    std::istringstream iss(rawWords);
    std::string word;


    while(iss >> word)
    {
        if (word.length() >= 2)
        {
          size_t position = 0;
          //Processes word and adds to wordSet if needed
          while (( position = word.find_first_of(".,;:'\"!?{}[]()")) != std::string::npos)
          {
            std::string wordFrag = word.substr(0,position);
            if (wordFrag.length() >= 2)
            {
              wordSet.insert(wordFrag);
            }
            // Removes processed portion of word
            word.erase(0, position+1);
          }
        }
        if (!word.empty() && word.length() >= 2 )
        {
          wordSet.insert(word);
        }
    }
    return wordSet;
}


/**************************************************
 * COMPLETED - You may use the following functions
 **************************************************/

// Used from http://stackoverflow.com/questions/216823/whats-the-best-way-to-trim-stdstring
// trim from start
std::string &ltrim(std::string &s) {
    s.erase(s.begin(), 
	    std::find_if(s.begin(), 
			 s.end(), 
			 std::not1(std::ptr_fun<int, int>(std::isspace))));
    return s;
}

// trim from end
std::string &rtrim(std::string &s) {
    s.erase(
	    std::find_if(s.rbegin(), 
			 s.rend(), 
			 std::not1(std::ptr_fun<int, int>(std::isspace))).base(), 
	    s.end());
    return s;
}

// trim from both ends
std::string &trim(std::string &s) {
    return ltrim(rtrim(s));
}
