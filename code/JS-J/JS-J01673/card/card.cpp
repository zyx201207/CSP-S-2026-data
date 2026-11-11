#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5,M=3e5+5;
int fir[M],dp[M],a[N];
vector<int> vec[M];
void dfs(int id){
    for(int v:vec[id]){
        dfs(v);
        dp[id]+=dp[v];
    }
}
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        fir[a[i]]=i;
        dp[a[i]]++;
    }
    for(int i=1;i<=m;i++){
        vec[a[fir[i]+1]].push_back(i);
    }
    dfs(a[n]);
    for(int i=1;i<=m;i++)cout<<dp[i]<<" ";
    return 0;
}
