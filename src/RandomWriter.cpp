/*
 * File: RandomWriter.cpp
 * ----------------------
 * Name: Nicholas Pataki
 */

#include <fstream>
#include <iostream>
#include <string>
#include "console.h"
#include "map.h"
#include "random.h"
#include "strlib.h"
#include "vector.h"
#include "filelib.h"
#include "simpio.h"
using namespace std;

#define NUMBER_OF_CHARACTERS 2000

/* Function Prototypes */
string getSourceText();
Map<string,Vector<char> > analyzeText(string str, int k);
string chooseSeed(Map<string, Vector<char> > & map);
string generateText(Map< string,Vector<char> > & map, string str);


int main() {
    cout << "This program reads one of three source texts, build an order-k Markov model for it, ";
    cout << "and generates random output that follows the frequency patterns of the model." << endl;
    cout << endl;
    string text = getSourceText();
    cout << endl;
    int k = getInteger("What order of analysis (1 to 10):");
    Map< string,Vector<char> > map = analyzeText(text,k);
    string seed = chooseSeed(map);
    string randomText = generateText(map, seed);
    cout << endl;
    cout << randomText;
    return 0;
}


/*
 * Function: getSourceText();
 * Usage: string str = getSourceText();
 * -------------------------------------
 * This implementation prompts user for a filename and
 * returns that file as a string.
 *
 */

string getSourceText() {
    cout << "The available data files are Hamlet.txt, Middlemarch.txt, and TomSawyer.txt." << endl;
    ifstream stream;
    cout << endl;
    string filename = promptUserForFile(stream, "Please enter filename containing source text:");
    string text = readEntireFile(filename);
    return text;
}

/*
 * Function: analyzeText();
 * Usage: Map<int,Vector<char> > analyzeText(string text, int k);
 * -------------------------------------
 * This implementation takes in a string of text and an integer k. It returns
 * a Map where each key is a k-character sequence found in the string.
 * The associated value is a vector of all the characters that follow that
 * seed in the string. This vector will likely contain multiple entries and
 * duplicate values. These duplicates represent higher probability transitions
 * from the Markov state.
 *
 */

Map<string,Vector<char> > analyzeText(string text, int k) {
    Map<string,Vector<char> > map;
    for(int i = 0; i < text.size()-k; i++) {
        map[text.substr(i,k)].add(text[i+k]);
    }
    return map;
}


/*
 * Function: chooseSeed();
 * Usage: string chooseSeed(Map< string,Vector<char> > & map);
 * -------------------------------------
 * Chooses the sequence that appears most frequently in the source.
 * Sequences are stored in the map that is passed in. If there are
 * several sequences tied for most frequent this implementation
 * returns the last occurence of those sequences.
 */


string chooseSeed(Map<string, Vector<char> > & map) {
    string seed;
    int n = 0;
    for(string seq : map) {
        if(map.get(seq).size() > n) {
            n = map.get(seq).size();
            seed = seq;
        }
    }
    return seed;
}


/*
 * Function: generateText();
 * Usage: string generateText(Map< string,Vector<char> > &map, string str);
 * -------------------------------------
 *
 */

string generateText(Map<string, Vector<char> > & map, string str) {
    cout << endl;
    string seed = str;
    string randomText = str;
    for (int i = 0; i < NUMBER_OF_CHARACTERS; i++) {
        int vectorLength = map[seed].size();
        int indexDraw = randomInteger(0, vectorLength-1);
        seed = seed.substr(1,seed.length()-1) + map[seed][indexDraw];
        randomText += seed[seed.size()-1];
    }
    return randomText;
}










