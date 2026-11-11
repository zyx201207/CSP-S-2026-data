#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define M 300009
#define N 500008
ull cards[N];
ull pos[M];
ull result[M];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ull m,n;
    cin>>n>>m;
    for(int i = 0;i < n;++i){
        cin>>cards[i];
    }

    for(int a = 0;a < n;++a){
        int k = a;
        for(int i = a;i < n;++i,++k){
            if(pos[cards[i]]){
                k = pos[cards[i]] - 1;
                for(int j = k;j <= i;++j){
                    pos[cards[j]] = 0;
                }
            }
            pos[cards[i]] = k + 1;
        }
        for(int i = 1;i <= m;++i){
            if(pos[i])
                ++result[i];
            pos[i] = 0;
        }
    }
    for(int i = 1;i <= m;++i){
        cout<<result[i]<<' ';
    }
    return 0;
}
