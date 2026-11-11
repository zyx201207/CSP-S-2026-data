#include<bits/stdc++.h>
using namespace std;
int n,m,maxn=-1;
int a[20005],num[20005];
vector<int> vis;
void dfs(int l,int pre,vector<int>& vis){
    if(l==m){
        int t=a[vis[0]];
        for(int i=1;i<vis.size();++i){
            t= (t&a[vis[i]]);
        }/*
        for(int i=0;i<vis.size();++i){
            cout<<vis[i]<<" ";
        }cout<<"\n";*/
        maxn=max(maxn,t);
        return;
    }
    if(pre>n-m+2)return;
    for(int i=pre+1;i<=n;++i){
        vis.push_back(i);
        dfs(l+1,i,vis);
        vis.pop_back();
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;++i)cin>>a[i];
    for(int i=1;i<=m;++i)num[i]=i;
    dfs(0,0,vis);
    cout<<maxn;
    return 0;
}

