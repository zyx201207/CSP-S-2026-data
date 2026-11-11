#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,m,a[N],last[N],to[N],f[N];
long long ans[N];
queue<int>q;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        ++ans[a[i]];
        last[a[i]]=i;
    }
    a[n+1]=0;
    for(int i=1;i<=m;i++){
        to[i]=a[last[i]+1];
        if(to[i]) ++f[to[i]];
    }
    for(int i=1;i<=m;i++)
        if(!f[i]) q.push(i);
    while(!q.empty()){
        int x=q.front();
        q.pop();
        if(!to[x]) continue;
        ans[to[x]]+=ans[x];
        --f[to[x]];
        if(!f[to[x]]) q.push(to[x]);
    }
    for(int i=1;i<=m;i++) cout<<ans[i]<<' ';
    return 0;
}
