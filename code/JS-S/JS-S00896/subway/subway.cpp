#include <bits/stdc++.h>
using namespace std;
constexpr int N=1e6+6;
int c,n,m,d,q,k;
long long ans,w[N];
struct Node{
    int line[21],cnt=0;
    long long time[21];
}s[N];
int dji(int u,int v){
    long long dis=LLONG_MAX;
    //time&node
    //for(int i=1;i<=s[u].cnt;i++)
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=n;i++) cin>>w[i];
    for(int i=1;i<=m;i++){
        int x;
        cin>>k;
        for(int j=1;j<=k;j++){
            cin>>x;
            s[x].line[++s[x].cnt]=i;
            cin>>s[x].time[s[x].cnt];
        }
    }
    int u,v;
    while(q--){
        cin>>u>>v;
        ans+=w[u]+w[v];
        dji(u,v);
    }
    return 0;
}
