#include <bits/stdc++.h>
using namespace std;
int n, m, num[1000005], card[1000005], mx=0;
int main(){
    freopen("card.in", "r", stdin);
    freopen("card.out", "m", stdout);
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> num[i];
    }
    for(int i = 0; i < n; i++){
        for(int x = i; x < n; x++){
            card[x] = num[x];
            for(int j = 0; j <x; j++){
                if(card[j] = card[x]){
                    while(j = x){
                        card[x] = card[j];
                        j += 1;
                }
            }
        }
        }
        for(int j = 0; j < n-i; j++){
            if(card[i] = card[j]){
                mx += 1;
                break;
            }
        }
    }
    cout << mx;
    return 0;
    }
