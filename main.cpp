#include <random>
#include <algorithm>
#include <iterator>
#include <iostream>
#include <vector>
#include <utility>
#define RUNS 100000

using namespace std;


int main() {
    srand(time(NULL));

    vector<pair<int,char>> deck;
    vector <char> suit = {'d', 'h', 's', 'c'};
    // populate the deck
    for (int i = 1; i <= 13; i++){
        for (int j = 0; j < 4; j++) {
            deck.push_back(make_pair(i,suit[j]));
        }
    }
    /*for (int i = 0; i < 52; i++){

        cout << deck[i].first << " " << deck[i].second << endl;
    }*/

    for (int q = 0; q < 500; q++){

        int count = 0;

        for (int p = 0; p < RUNS; p++){

            random_device rd;
            mt19937 g(rd());

            // shuffle the deck
            shuffle(deck.begin(), deck.end(), g);

            int hearts = 0;
            int aces = 0;
            int faces = 0;

            // check the first 13 cards
            for (int i = 0; i < 13; i++){
                if (deck[i].first == 1){ // check if ace
                    aces++;
                }
                else if (deck[i].first == 11 || deck[i].first == 12 || deck[i].first == 13 ){ // check if face card
                    faces++;
                }
                if(deck[i].second == 'h'){ // check if heart
                    hearts++;
                }
            }
            // check if conditions are met
            if (hearts >= 6 && faces == 5 && aces == 2){
                count++;
            }
        }
        cout << (float)count / RUNS << endl;
    }

    return 0;
}



