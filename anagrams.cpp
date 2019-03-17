#include "anagrams.hpp"

using namespace std;

Frq_hist create_frq(const string word);//crée un histogramme des fréquences des lettres dans un mot

int compare_frq(const Frq_hist& fa, const Frq_hist& fb, Frq_hist& output);//compare deux histos -1 si <0, 0 si =0, 1 si >0 false sinon avec l'histo de différence dans output

Frq_hist create_frq(const string word){//TOTEST O(max_word_size) not sure find then insert -> better operation ? if not still (log 26)^2 but rather ugly
    //créer la map vide
    Frq_hist frq;

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

            frq.second.push_back((*iter));//ajout du caractère dans la string retenant le mot
        }
    }

    //ajouter clé '#' avec value cnt
    frq.first.insert({'#', size});

    return frq;
}

int compare_frq(const Frq_hist& fa, const Frq_hist& fb, Frq_hist& output){//revoye -1 si b non compris dans a, 0 si a = b et 1 si b compris dans a.  Renvoye dans output la différence a-b si result = 0 ou 1
    output = fa;
    //cout << "fa: " << output.second << " fb: " << fb.second << endl;
    if(fa.first.size() < fb.first.size() || fa.first.at('#') < fb.first.at('#'))//if b use more letters than a return a into output and 1 as result
        return -1;

    try{
        for(auto lettre = ++fb.first.cbegin(); lettre != fb.first.cend(); ++lettre){
            //cout << "key: " << lettre->first << " value: " << lettre->second << endl;
            output.first.at(lettre->first) -= lettre->second;
        }
    }catch(std::out_of_range&){
        return -1;
    }

    return -1;
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

    vector<pair<Dictionary::const_iterator, Frq_hist>> stk;//conserve l'emplacement du mot et l'input calculé jusque là
    int test;
    Frq_hist diff_frq;
    Frq_hist searched_frq;

    //Enregister l'input;
    stk.push_back({dict.cbegin(), create_frq(input)});
    //Parcourir le dico
    do{
        searched_frq = stk.back().second;
        for(auto word = stk.back().first++; word != dict.cend(); ++word){
            test = compare_frq(searched_frq, (*word), diff_frq);
            if(test == 0){//anagram complet
                //print anagram (with stack)
            }else if(test >= 1){//anagram partiel
                stk.push_back({word, diff_frq});
                searched_frq = diff_frq;//possible to just do that or need to implement copy
            }
        }
        if(!stk.empty())
            stk.pop_back();//supprime le dernier élément du stack après avoir fouillé le reste du dictionnaire*/
    }while(!stk.empty());

    return anags;
}

