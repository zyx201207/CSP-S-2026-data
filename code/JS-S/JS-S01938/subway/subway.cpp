#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=514;
const int M=1145;
int c,n,m,d,q;
int w[M],k[N];
int aa,ta,x,y,ab,tb;
ll t[M][M];
ll dep[M];
ll fa[M];
bool vis[M];
void dfs(int nn){
    vis[nn]=true;
    for(int i=1;i<=m;i++){
        if(t[nn][i]!=0&&!vis[i]){
            dep[i]=dep[nn]+t[nn][i];
            dfs(i);
        }
    }
}
int main(){

    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    dep[1]=0;
    for(int i=1;i<=n;i++){
        cin>>k[i];
        cin>>aa>>ta>>ab>>tb;
        t[aa][ab]=ta+tb;
        t[ab][aa]=ta+tb;
    }
    for(int i=1;i<=m;i++){
        vis[i]=false;
    }
    dfs(1);
    while(q--){
        cin>>x>>y;
        cout<<w[x]+dep[x]+dep[y]+w[y]<<'\n';
    }
    return 0;
}
