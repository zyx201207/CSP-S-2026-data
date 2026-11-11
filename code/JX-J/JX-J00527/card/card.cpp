#include <bits/stdc++.h>
using namespace std;
int main(){
    //freopen("card.in","r",stdin);
    //freopen("card.out","w",stdout);
    int n,m;
    int a[20001]={},d[20001]={},t[20001][5]={},t2[20001]={};
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;i++){
            d[j]=a[j];
            t[d[j]][1]++;
            if((t[d[j]][1])==1) t[d[j]][2]=j;
            if(t[d[j]][1]==2){
                for(int k=t[d[j]][2];k<=n;k++){
                    d[k]=0;
                }
                d[t[d[j]][1]]=d[j];
            }
        }
        for(int j=1;j<=n;j++){
            for(int k=1;k<=n;k++){
                if(d[j]=a[k]){
                    t2[a[k]]++;
                }
            }
        }
    }
    for(int i=1;i<=n;i++){
        if(t2[i]!=0){
            cout<<t2[i];
        }
    }
    return 0;
}
