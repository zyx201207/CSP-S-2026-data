#include <bits/stdc++.h>
using namespace std;
int a[500005];
bool card[500005];
int cnt[300005];

int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }
    for(int i = 1;i <= n;i++){
        string game = "";
        int k = a[i];
        for(int j = i;j <= n;i++){
            if(card[a[j]] == 0){
                card[a[j]] = 1;
                game += a[j]+'0';
            }
            else{
                string t = game;
                game = "";
                int pos = 0;
                for(int p = 0;p < t.size();p++){
                    if(t[p] == k){
                        pos = p;
                    }
                }
                for(int p = 0;p < pos;p++){
                    game += t[p];
                }
                game += k;
            }
        }
        if(game.find(i+'0') != string::npos){
            cnt[i]++;
        }
    }
    for(int i = 1;i <= n;i++){
        if(cnt[i] != 0){
            cout << cnt[i] << " ";
        }
    }
    return 0;
}
