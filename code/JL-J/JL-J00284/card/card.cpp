#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    long long s[10001],k[10001],a[10001],b[10001]={},p[10001]={};
    for(int i=1;i<=n;i++){
        cin>>k[i];
        s[i]=k[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(j<i){
                s[j]=0;
            }else{
                for(int l=1;l<j;l++){
                    if(s[l]==k[j]){
                        for(int z=l;z<j;z++){
                            s[z]=0;
                        }
                        break;
                    }
                }
            }
        }
        for(int j=1;j<=n;j++){
            if(s[j]!=0){
                p[k[j]]++;
            }
        }
        for(int j=1;j<=n;j++){
            s[j]=k[j];
        }
    }
    for(int i=1;i<=m;i++){
        cout<<p[i]<<" ";
    }
    return 0;
}
