#include "anagrams.hpp"

using std::string;
using std::vector;

Frq_hist create_frq(const string word);//crée un histogramme des fréquences des lettres dans un mot

//Frq_hist equal_frq(const Frq_hist& fa, const Frq_hist& fb);//compare deux histogramme de fréquence des lettres et renvoye la différence si égale renvoye null

Frq_hist create_frq(const string word){//TOTEST O(max_word_size) not sure find then insert -> better operation ? if not still (log 26)^2 but rather ugly
    //créer la map vide
    Frq_hist frq;//initialisation ? pointeur ?

    //initialiser compteur de taille
    int size = 0;

    //parcourir le mot
    for(auto iter = word.cbegin; iter != word.cend(); ++iter){
        //incrémnter cnt pour chaque lettre
        ++cnt;

        //si la lettre déjà clé de la map, ++value sinon ajouter clé avec value 1
        if(frq.find((*iter))){//parenthesis ?
            ++frq[(*iter)];//increment la value de la clé
        }else{
            frq.insert((*iter), 1);//ajoute la clé et sa value
        }//more efficient/elegant ? maybe with response of operation that access to a value
    }

    //ajouter clé '#' avec value cnt (EST CE NECESSAIRE ?)
    frq.insert('#', cnt);//TOTEST

    return frq;
}

/*Frq_hist equal_frq(const Frq_hist& fa, const Frq_hist& fb){

}*/

Dictionary create_dictionary(const string& filename){
    Dictionary dict;//tmps
    (void)filename;

    //tmps TOTEST
    /*std::map map_1 {{a, 1}, {d, 10}, {w, 4}};
    std::map map_1 {{b, 3}, {e, 5}, {c, 1}};
    std::map map_1 {{a, 2}, {d, 10}, {z, 3}}; 
    Dictionary dict{map_1, map_2, map_3}*/

    //Creer le dict vide
    //Dictionary dict;

    //ouvrir le fichier (gestion des exceptions ?)

    //Parcourir le fichier ligne par ligne

    //lowercase(word)

    //enregister: map<char, int> create_frq(word) renvoye l'élément map correspondant qu'on pushback sur le vecteur dict (conserve l'ordre alpha)

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

