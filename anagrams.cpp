#include "anagrams.hpp"

using namespace std;

Frq_hist create_frq(const string word);//crée un histogramme des fréquences des lettres dans un mot

int compare_frq(const Frq_hist& fa, const Frq_hist& fb, Frq_hist& output);//compare deux histos -1 si <0, 0 si =0, 1 si >0 false sinon avec l'histo de différence dans output

Frq_hist create_frq(const string word){//TOTEST O(max_word_size) not sure find then insert -> better operation ? if not still (log 26)^2 but rather ugly
    //créer la map vide
    Frq_hist frq;//initialisation ? pointeur ?

    //initialiser compteur de taille
    int size = 0;

    //parcourir le mot
    for(auto iter = word.cbegin(); iter != word.cend(); ++iter){
        //ignorer si non lowercase
        if(islower((*iter))){
            //incrémenter cnt pour chaque lettre
            ++size;

            //map[] operator increment key and create new ones
            frq.first[(*iter)]++;
        }
    }

    //ajouter clé '#' avec value cnt
    frq.first.insert({'#', size});

    return frq;
}

int compare_frq(const Frq_hist& fa, const Frq_hist& fb, Frq_hist& output){
    (void)fa;
    (void)fb;
    (void)output;
    return 0;
}

Dictionary create_dictionary(const string& filename){//retun NULL if error TO CHECK
    //Creer le dict vide
    Dictionary dict;

    //ouvrir le fichier (gestion des exceptions ?)
    ifstream fin(filename);
    if(!fin){
        cerr << "Error: Cannot open text file";
        return dict;//TO TEST, OK?
    }

    //Parcourir le fichier ligne par ligne
    string s;
    while(fin >> s){
        dict.push_back(create_frq(s));
    }

    return dict;
}

std::vector<std::vector<string>> 
anagrams(const string& input, const Dictionary& dict, unsigned max){
    vector<vector<string>> anags;//tmps
    (void)max;

    //Enregister l'input
    Frq_hist input_frq = create_frq(input);

    vector<Dictionary::const_iterator> stk;

    int test;
    Frq_hist diff_frq;
    //Parcourir le dico
    do{
        for(auto word = dict.cbegin(); word != dict.cend(); ++word){
            test = compare_frq(input_frq, (*word), diff_frq);
            if(test == 0){//anagram complet
                
            }else if(test >= 1){//anagram partiel
                stk.push_back(word);
            }
        }
    }while(!stk.empty());

    return anags;
}

