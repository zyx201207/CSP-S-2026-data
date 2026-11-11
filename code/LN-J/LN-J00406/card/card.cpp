#include<bits/stdc++.h>
using namespace std;
int a[500005],b[300005],t[500005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m,z = 0;
    cin>>n>>m;
    for(int i = 1; i <= n; i++){
        cin>>a[i];
    }

    for(int i = 1; i <= n; i++){
        for(int j = i; j <= n; j++){
            t[++z] = a[j];
            for(int k = 1; k <= z - 1; k++){
                if(t[z] == t[k]){
                    for(int q = k; q <= z - 1; q++){
                        t[q] = 0;
                    }
                }
            }
        }
        for(int j = 1; j <= z; j++){
            if(t[j] > 0){
                b[t[j]]++;
            }
        }
        z = 0;
    }

    for(int i = 1; i <= m; i++){
        cout<<b[i]<<" ";
    }

    return 0;
}

