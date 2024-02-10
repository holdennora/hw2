#ifndef UTIL_H
#define UTIL_H

#include <string>
#include <iostream>
#include <set>


/** Complete the setIntersection and setUnion functions below
 *  in this header file (since they are templates).
 *  Both functions should run in time O(n*log(n)) and not O(n^2)
 */
template <typename T>
std::set<T> setIntersection(std::set<T>& s1, std::set<T>& s2)
{
  // Initailize the set contain the intersections of s1 and s2
  std::set<T> output;
  // Initailize interators for s1/s2
  typename std::set<T>::iterator iter1 = s1.begin();
  typename std::set<T>::iterator iter2 = s2.begin();
  // Creates case to end the loop
  while (iter1 != s1.end() && iter2 != s2.end())
  {
    // if and else if case checks for inequality and
    // continues iterating if unequal
    if(*iter1 < *iter2)
    {
      ++iter1;
    }
    else if(*iter1 > *iter2)
    {
      ++iter2;
    }
    // if values in s1 and s2 are equal, inserts values
    // into output set 
    else
    {
      output.insert(*iter1);
      ++iter1;
      ++iter2;
    }
  }
  return output;
}
template <typename T>
std::set<T> setUnion(std::set<T>& s1, std::set<T>& s2)
{
  // Initailize the set contain the intersections of s1 and s2
  std::set<T> output;
  // Initailize interators for s1/s2
  typename std::set<T>::iterator iter1 = s1.begin();
  typename std::set<T>::iterator iter2 = s2.begin();
  // Creates case to end the loop
  while (iter1 != s1.end() && iter2 != s2.end())
  {
    // adds values from s1 and s2
    if(*iter1 < *iter2)
    {
      output.insert(*iter1);
      ++iter1;
    }
    else if(*iter1 > *iter2)
    {
      output.insert(*iter2);
      ++iter2;
    }
    // if values in s1 and s2 are equal, inserts values
    // into output set 
    else
    {
      output.insert(*iter1);
      ++iter1;
      ++iter2;
    }
  }
  // insert last elements
  output.insert(iter1, s1.end());
  output.insert(iter2, s2.end());
  return output;
}

/***********************************************/
/* Prototypes of functions defined in util.cpp */
/***********************************************/

std::string convToLower(std::string src);

std::set<std::string> parseStringToWords(std::string line);

// Used from http://stackoverflow.com/questions/216823/whats-the-best-way-to-trim-stdstring
// Removes any leading whitespace
std::string &ltrim(std::string &s) ;

// Removes any trailing whitespace
std::string &rtrim(std::string &s) ;

// Removes leading and trailing whitespace
std::string &trim(std::string &s) ;
#endif
