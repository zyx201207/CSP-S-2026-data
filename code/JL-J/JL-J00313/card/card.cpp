#include<bits/stdc++.h>
using namespace std;
int h[500005],jl[300005],g[500005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int a,k;
    cin >> a >> k;
    for(int i=1;i<=a;i++){
        cin >> h[i];
        g[i]=h[i];
    }
    for(int i=1;i<=a;i++){
        for(int j=i;j<=a;j++){
            for(int f=i;f<j;f++){
                if(h[j]==h[f]){
                    for(int d=f;d<j;d++){
                        h[d]=0;
                    }
                }
            }
        }
        for(int j=i;j<=a;j++){
            jl[h[j]]++;
        }
        for(int j=1;j<=a;j++){
            h[i]=g[i];
        }
    }
    jl[2]++;
    for(int i=1;i<=k;i++){
        cout << jl[i] << ' ';
    }
    return 0;
}
