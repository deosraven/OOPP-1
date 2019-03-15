#include <string>
#include <vector>
#include <iostream>
#include <limits>
#include <stdexcept>

#include "anagrams.hpp"

using std::string;
using std::vector;
using std::cout;
using std::endl;
using std::strtoul;

int main(int argc, char* argv[]){
    const string error_arguments = "Error: Format is \n./anagrams input_string dictionary_file max_words output_file";

    if(argc != 5){
        cout << error_arguments << endl;
        return -2;
    }

    //get arguments
    try{
        const string input_string = argv[1];
        const string dict_filename = argv[2];
        const unsigned long tmp_max = strtoul(argv[3], nullptr, 10);//invalid argument treated as 0
        if(tmp_max >= std::numeric_limits<unsigned int>::max())
            throw std::invalid_argument("max_words error");
        const unsigned max = unsigned(tmp_max);
        const string output_filename = argv[4];

        //create dictionary
        const Dictionary dict = create_dictionary(dict_filename);

        //find all uniques anagrams
        vector<vector<string>> anag = anagrams(input_string, dict, max);

        //output result in exit file

    }catch(std::invalid_argument&){
        cout << error_arguments << endl;
        return -2;
    }

    return 0;
}

