#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 1;
int n, m;
int a[N];
int last[N];//last[i]means,the count of when the end of the game the color i 
int main(){
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }
    for(int i = 1;i <= n;i ++){
        vector<int> game;
        for(int j = i;j <= n;j ++){
            int k = a[j];
            vector<int> gg;
            game.push_back(k);
            for(int l = 0;l < game.size();l ++){
                gg.push_back(game[l]);
                if(game[l] == k){
                    break;
                }
            }
            game.clear();
            for(int l = 0;l < gg.size();l ++){
                game.push_back(gg[l]);
            }
        }
        for(int j = 0;j < game.size();j ++){
            //cout << game[j] << "     "; 
            last[game[j]] ++;
        }
        //cout << "-----------" << '\n';
    }
    for(int i = 1;i <= m;i ++){
        cout << last[i] << " ";
    }
    cout << '\n';
    return 0;
}