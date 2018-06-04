#include <random>
#include <algorithm>
#include <iterator>
#include <iostream>
#define RUNS 1000000
using namespace std;

typedef vector<int> vi;

vector<vi> combinations;
vi temp;
vi cards;
int cNum = 0;

void pretty_print(const vector<int>& v) {

    cout << "combination no " << (++cNum) << ": [ ";
    for (int i = 0; i < v.size(); ++i) { cout << v[i] << " "; }
    cout << "] " << endl;
}

void findComb(int offset, int k) {
    if (k == 0) {
        //pretty_print(temp);
        combinations.push_back(temp);
        return;
    }
    for (int i = offset; i <= cards.size() - k; ++i) {
        temp.push_back(cards[i]);
        findComb(i+1, k-1);
        temp.pop_back();
    }
}

int main() {
    srand(time(NULL));
    // deck with cards ace to jack, jack = 0
    vi deck = {1,1,1,1,2,2,2,2,3,3,3,3,4,4,4,4,5,5,5,5,6,6,6,6,7,7,7,7,8,8,8,8,9,9,9,9,10,10,10,10,0,0,0,0};
    int count = 0;
    for (int r = 0; r < RUNS; r++){

        random_device rd;
        mt19937 g(rd());

        // shuffle the deck
        shuffle(deck.begin(), deck.end(), g);

        // reset the chosen 5 cards and the combinations
        cards = {};
        temp = {};
        combinations = {};

        // get the combinations of k cards from the first n cards in the deck
        int n = 5, k = 3;

        // put the first 5 cards in the deck into "cards"
        for (int i = 0; i < n; ++i) {
            cards.push_back(deck[i]);
        }
        cNum = 0;
        // find all possible combinations of 3 cards
        findComb(0, k);

        for (int i = 0; i < combinations.size(); i++){
            int sum = 0;
            for (int j = 0; j < k; j++){
                sum += combinations[i][j];
            }
            if (sum == 0 || sum == 1 || sum == 2 || sum == 28 || sum == 29 || sum == 30){
                count++;
                //cout << "SUM TO: " << sum << " ON COMBINATION: " << i + 1 << endl;
                // break to avoid double counting
                break;
            }

        }


    }
    cout << count << endl;
    cout << (float)count / RUNS << endl;
    return 0;
}



