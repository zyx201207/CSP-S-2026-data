#include<bits/stdc++.h>
using namespace std;
long long a=0,b=0,c=0,d=0,e=0;
int f[100000],g[100000],h[100000],x[100000];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>a>>b;
    for(int i=1;i<=a;i++){
        cin>>f[i];
    }
    for(int k=1;k<=a;k++){
        for(int i=1;i<=b;i++){
            h[i]=0;
        }
        c=0;
        for(int i=k;i<=a;i++){
            c++;
            g[f[i]]++;
            if(g[f[i]]==2){
                g[f[i]]=0;
                d=f[i];
                for(int j=1;j<=c;j++){
                    if(h[j]==d){
                        c=j;
                        break;
                    }
                }
            }
            h[c]=f[i];
        }
        for(int i=1;i<=c;i++){
            x[h[i]]++;
        }
    }
    for(int i=1;i<=b;i++){
        cout<<x[i]<<" ";
    }
    return 0;
}

