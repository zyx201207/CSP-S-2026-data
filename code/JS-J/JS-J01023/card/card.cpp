#include <bits/stdc++.h>
using namespace std;
const int N=5e5+3;
int n,m,a[N],ls[N],ans[N],cc[N],p[N],to[N],tot;
vector<int>v[N];
void dfs(int x){
    for(auto y:v[x]) dfs(y),cc[x]+=cc[y];
    ans[to[x]]+=cc[x];
}
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=n;i;i--){
        int j=0;
        if(!ls[a[i]]) j=i+1;
        else j=ls[a[i]];
        if(!ls[a[i]]){
            v[p[j]].push_back(++tot),ls[a[i]]=i;
            p[i]=tot;to[tot]=a[i];
        }else p[i]=p[j];
        cc[p[i]]++;
    }
    dfs(0);
    for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
    cout<<"\n";
}
