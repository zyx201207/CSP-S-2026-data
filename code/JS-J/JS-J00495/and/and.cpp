#include<bits/stdc++.h>
using namespace std;
int a[200009],mx,m,n;
void dfs(int ans,int i,int num){
    if(num==m){
        mx=max(mx,ans);
        return;
    }
    for(int j=i+1;j<=n-m+i;++j){
        dfs(ans&a[j],j,num+1);
    }
}
int main(){
    ios::sync_with_stdio(false),cin.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;++i){
        cin>>a[i];
        mx=max(mx,a[i]);
    }
    if(m==1) cout<<mx;
    else{
        mx=0;
        for(int i=1;i<=n-m+1;++i){
            dfs(a[i],i,1);
        }
        cout<<mx;
    }
}
