#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[1010110],t[1010110],pos[1010110],nxt[1010110];
int nt[1010110],val[1010110],sz[1010110];
vector<int>g[1010110];
void dfs(int u){
    sz[u]=1;
    //cout<<"noe is "<<u<<endl;
    for(int i=0;i<g[u].size();i++){
        dfs(g[u][i]);
        sz[u]+=sz[g[u][i]];
    }
    val[a[u]]+=sz[u];
    //cout<<"add "<<sz[u]<<" "<<g[u].size();
}
signed main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        if(pos[a[i]]){
            nxt[pos[a[i]]]=i;
        }
        pos[a[i]]=i;
    }nt[n]=0;
    for(int i=n;i>=1;i--){
        if(nxt[i]){
            nt[i]=nt[nxt[i]];
        }else nt[i]=i+1;
       if(n<200000){int p=i;
        while(p){
           val[a[p]]+=1;
           p=nt[p];
        }}
    }
    if(n>=200000){
        for(int i=1;i<=n;i++){
        g[nt[i]].push_back(i);
        //cout<<nt[i]<<" "<<i<<endl;
    }
    dfs(n);
    }
    for(int i=1;i<=m;i++){
        cout<<val[i]<<" ";
    }
    return 0;
}/*













inclusteam
dcciyiyz
tdchuidiervsxt
2026/10/31 8:30:00
*/
