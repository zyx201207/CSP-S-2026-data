#include <bits/stdc++.h>

using namespace std;

namespace Solve {
    void main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        freopen("card.in", "r", stdin);
        freopen("card.out", "w", stdout);
        
        int n, m;
        cin >> n >> m;
        int bucket[m+1] = {0};
        int cards[n+1];
        vector<int> cards_in_hands;
        for(int i = 1; i <= n; i++){
            cin >> cards[i];
        }
        for(int i = 1; i <= n; i++){
            for(int j = i; j <= n; j++){
                if(find(cards_in_hands.begin(), cards_in_hands.end(), cards[j]) != cards_in_hands.end()){
                    int head = 0;
                    for(int k = 0; k < cards_in_hands.size(); k++){
                        if(cards_in_hands[k] == cards[j]){
                            head = k;
                            break;
                        }
                    }
                    int length= cards_in_hands.size();
                    for(int k = head; k < length + 1; k++){
                        cards_in_hands.pop_back();
                    }
                }
                cards_in_hands.push_back(cards[j]);
            }
            for(int cr : cards_in_hands){
                bucket[cr]++;
            }
            
            cards_in_hands.clear();
        }

        for(int count : bucket){
            cout << count << " ";
        }
    }
}

int main() {
    Solve::main();
    return 0;
}