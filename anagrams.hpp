#ifndef ANAGRAMS_HH
#define ANAGRAMS_HH

#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <iostream>

typedef std::pair<std::map<char, int>, std::string> Frq_hist;//pair of frenquency histogram and word
typedef std::vector<Frq_hist> Dictionary;//vector of frequency histogram

Dictionary create_dictionary(const std::string& filename);

std::vector<std::vector<std::string>> 
anagrams(const std::string& input, const Dictionary& dict, unsigned max);

#endif

