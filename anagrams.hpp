#ifndef ANAGRAMS_HH
#define ANAGRAMS_HH

#include <string>
#include <vector>

typedef std::vector<std::string> Dictionary;//temporary a vector of string

Dictionary create_dictionary(const std::string& filename);

std::vector<std::vector<std::string>> 
anagrams(const std::string& input, const Dictionary& dict, unsigned max);

#endif

