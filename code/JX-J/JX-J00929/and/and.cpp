#include<iostream>
#include<cstdio>
#include<algorithm>
#define int long long
using namespace std;
int a[200010],n,m;
int dl[200010],mxn=-1e18;
void rel(){
    int res=dl[1];
    for(int i=2;i<=m;++i)
        res&=dl[i];
    mxn=max(mxn,res);
}
bool chk(int n,int cho){
    for(int i=1;i<cho;++i)
        if(n==dl[i])
        return false;
    return true;
}
void dfs(int cho){
    if(cho>m){
        rel();
        return;
    }
    for(int i=1;i<=n;++i){
        if(chk(a[i],cho)){
           dl[cho]=a[i];
        dfs(cho+1);}
    }
}
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;++i)cin>>a[i];
    dfs(1);
    cout<<mxn;
}
