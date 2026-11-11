#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],ans,c[200005];
void dfs(int dep,int num){
    if(num>n) return;
    if(dep>m){
        c[0]=c[1];
        for(int i=2;i<=m;i++) c[0]&=c[i];
        if(c[0]>ans) ans=c[0];
    }
    else{
        c[dep]=a[num];
        dfs(dep+1,num+1);
        c[dep]=0;
        dfs(dep,num+1);
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    if(n==m){
        ans=a[1];
        for(int i=2;i<=n;i++) ans&=a[i];
        cout<<ans;
        return 0;
    }
    dfs(1,1);
    cout<<ans;
    return 0;
}
