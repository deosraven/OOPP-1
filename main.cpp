#include <string>
#include <vector>
#include <iostream>
#include <limits>
#include <stdexcept>
#include <fstream>

#include "anagrams.hpp"

using std::string;
using std::vector;
using std::cout;
using std::endl;
using std::strtoul;
using std::ofstream;

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

        //output dictionary in a file for test purpose
        ofstream out_a("dict_output.txt");
        if(!out_a)
            throw std::ios_base::failure("Error: Failed to open dictionnary output file"); 
        for(auto word = dict.cbegin(); word != dict.cend(); ++word){
            for(auto letter = word->cbegin(); letter != word->cend(); ++letter){
                out_a << "(" << letter->first << ", " << letter->second << ") ";
            }
            out_a << endl;
        }
        out_a.close();

        //find all uniques anagrams
        const vector<vector<string>> anag = anagrams(input_string, dict, max);

        //output result in exit file
        ofstream out_b(output_filename);
        if(!out_b)
            throw std::ios_base::failure("Error: Failed to open output file"); 
        for(auto line = anag.cbegin(); line != anag.cend(); ++line){
            for(auto word = line->cbegin(); word != line->cend(); ++word){
                out_b << (*word) << " ";
            }
            out_b << endl;
        }
        //out_b.close(); TOTEST

    }catch(std::invalid_argument&){
        cout << error_arguments << endl;
        return -2;
    }catch(std::ios_base::failure& f){
        cout << f.what() << endl;
        return -3;
    }

    return 0;
}

