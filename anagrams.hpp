#ifndef ANAGRAMS_HH
#define ANAGRAMS_HH

#include <string>
#include <vector>
#include <map>

typedef std::map<char, int> Frq_hist;
typedef std::vector<Frq_hist> Dictionary;//vector of map (key is letter and value is letter frequency in a word) (key '#' is for stocking size of word)

Dictionary create_dictionary(const std::string& filename);

std::vector<std::vector<std::string>> 
anagrams(const std::string& input, const Dictionary& dict, unsigned max);

#endif

