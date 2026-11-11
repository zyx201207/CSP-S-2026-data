#include <bits/stdc++.h>
using namespace std;
int n,m;
int ans[300005];
int a[300005];
int vis[300005];
int findl(int i,int j){
    for(int k=i;k<n;k++){
        if(a[k]==j){
            return k;
        }
    }
    return 0;
}
int findr(int i,int j){
    for(int k=n-1;k>=i;k--){
        if(a[k]==j){
            return k;
        }
    }
    return 0;
}
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
            memset(vis,0,sizeof(vis));
        for(int j=1;j<=m;j++){
            int l=findl(i,j);
            int r=findr(i,j);
           // cout<<l<<" "<<r<<endl;
            if(l!=r){
                for(int jj=l;jj<r;jj++){
                    vis[jj]=1;
                }
            }
        }
        for(int ii=i;ii<n;ii++){
            if(vis[ii]==0){
                ans[a[ii]]++;
            }
        }
        //cout<<"ans:";
        //for(int ij=1;ij<=m;i++){
        //    cout<<ans[ij]<<" ";
        //}
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}
