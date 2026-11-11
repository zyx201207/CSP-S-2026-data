#include<bits/stdc++.h>
using namespace std;
int n,m,k[500001],t[500001],tt=0,ans[500001];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>k[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=tt;j++){
            t[j]=0;
        }
        for(int j=i;j<=n;j++){
                //cout<<j;
            bool flag=0;
            for(int z=1;z<=tt;z++){
                if(t[z]==k[j]){
                    tt=z;
                    flag=1;
                    break;
                }
            }
            if(flag==0){
                tt++;
                t[tt]=k[j];
            }
        }
        for(int j=1;j<=tt;j++){
            ans[t[j]]++;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}



