#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a[n]={};
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int t[m]={};
    for(int i=0;i<n;i++){
        int w[n-i]={};
        //
        for(int j=i;i<=n;j++){
            int p=1;
            for(int u=0;u<=n-i;u++){
                if(a[j]==a[u]){
                   p=0;
                   for(int r=u;r<=n-i;r++){
                    w[r]=0;
                   }
                }
            }
            if(p==1){
                w[j]=a[j];
            }
        }
        //
        for(int j=0;j<=n-i;j++){
            t[w[j]]++;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<t[i];
    }
}
