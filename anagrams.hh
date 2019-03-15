#ifndef ANAGRAMS_HH
#define ANAGRAMS_HH

Dictionary create_dictionary(const std::string& filename);

std::vector<std::vector<std::string>> 
anagrams(const std::string& input, const Dictionary& dict, unsigned max);

#endif