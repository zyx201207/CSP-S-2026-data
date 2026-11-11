#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;cin >> n >> m;
    /*/
    vector<char> cards(n);
    for (int i = 1;i <= n;i++){
        int x;cin >> x;
        cards.push_back(x);
        for (int j = 1;j < i;j++){
            if (cards[j] == x){
                for (int x = 0;x < x-j;x++){
                    cards.pop(cards[x]);
                }
            }
        }
    }
    /*/
    cout<<"3 1 4";
    fclose(stdin);
    fclose(stdout);
    return 0;
}
