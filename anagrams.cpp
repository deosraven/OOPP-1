#include "anagrams.hpp"

using namespace std;

Frq_hist create_frq(const string word);//crée un histogramme des fréquences des lettres dans un mot

//Frq_hist equal_frq(const Frq_hist& fa, const Frq_hist& fb);//compare deux histogramme de fréquence des lettres et renvoye la différence si égale renvoye null

Frq_hist create_frq(const string word){//TOTEST O(max_word_size) not sure find then insert -> better operation ? if not still (log 26)^2 but rather ugly
    //créer la map vide
    Frq_hist frq;//initialisation ? pointeur ?

    //initialiser compteur de taille
    int size = 0;

    //parcourir le mot
    for(auto iter = word.cbegin(); iter != word.cend(); ++iter){
        //ignorer si non lowercase
        if(islower((*iter))){
            //incrémnter cnt pour chaque lettre
            ++size;

            //can be replaced by map[] operator that can increment value in new key place maybe solution with increment++ (after read)
            //frq[(*iter)]++;
            //si la lettre déjà clé de la map, ++value sinon ajouter clé avec value 1
            /*if(frq.find((*iter))){//parenthesis ?
                ++frq[(*iter)];//increment la value de la clé
            }else{
                frq.insert((*iter), 1);//ajoute la clé et sa value
            }//more efficient/elegant ? maybe with response of operation that access to a value*/
        }
    }

    //ajouter clé '#' avec value cnt
    frq.insert({'#', size});

    return frq;
}

/*Frq_hist equal_frq(const Frq_hist& fa, const Frq_hist& fb){

}*/

Dictionary create_dictionary(const string& filename){//retun NULL if error TO CHECK
    //Creer le dict vide
    Dictionary dict;

    //ouvrir le fichier (gestion des exceptions ?)
    ifstream fin(filename);
    if(!fin){
        cerr << "Error: Cannot open text file";
        //return nullptr;
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
    vector<vector<string>> agns;//tmps
    (void)input;
    (void)dict;
    (void)max;

    return agns;
}

