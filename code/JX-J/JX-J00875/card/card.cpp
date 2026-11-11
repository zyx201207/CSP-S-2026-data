#include<bits/stdc++.h>
using namespace std;
long long m,n,i=1,c=0;


int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    long long ans[m]={},ml[n]={};
    for(int i=1;i<n;i++){
            c++;
            cin>>ml[c];
            if(c==1){
                continue;
            }
        for(int j=0;j<c;j++){
            if(ml[c]==ml[j]){
                    int d=c;
                for(int b=j;j<c;b++){
                    ml[b]=0;
                    c--;
                }
            ml[j]=ml[d];
            }
        }
        for(int j=1;i<=c;j++){
              ans[ml[j]]++;
           }
    }
    for(int j=1;i<=m;j++){
              cout<<ans[j];
           }
    return 0;
}
