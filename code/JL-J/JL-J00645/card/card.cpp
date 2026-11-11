#include<bits/stdc++.h>
using namespace std;
const int N = 5e5+5;
const int M = 3e5+5;
int a[N],c[M];
int main(){
    ios::sync_with_stdio(false);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }
    for(int i = 1;i <= n;i++){
        int b[M] = {};
        for(int j = i;j <= n;j++){
            if(b[a[j]] > 0){
                for(int k = 1;k <= M;k++){
                    if(b[k] > b[a[j]]){
                        b[k] = 0;
                    }
                }
            }
            b[a[j]] = j;
        }
        for(int j = 1;j <= n;j++){
            if(b[j] > 0){
                c[j]++;
            }
        }
    }
    for(int i = 1;i <= M;i++){
        if(c[i] > 0) cout << c[i] << " ";
    }
    return 0;
}
