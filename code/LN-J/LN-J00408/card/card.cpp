#include<bits/stdc++.h>
using namespace std;
int n,m,a[300009],t[300009],bucket[300009];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    int T=n;
    while(T--){
        vector<int>q;
        int i=n-T;
        for(int j=i;j<=n;j++){
            t[j]=a[j];
        }
        for(int j=i;j<=n;j++){
            for(int k=j-1;k>=i;k--){
                if(t[k]==t[j]){
                    for(int l=k;l<j;l++){
                        t[l]=0;
                    }
                }
            }
        }
        for(int j=i;j<=n;j++){
            bucket[t[j]]++;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<bucket[i]<<" ";
    }
    return 0;
}
