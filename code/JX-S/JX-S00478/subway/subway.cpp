#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
using ll=long long;
const int maxn=5e5+5;
int c,n,m,d,Q;
int w[maxn],a[505][maxn];
int t[505][maxn];
int k[maxn];
int timee[maxn];
vector<vector<int>> g;
struct node{
    int x;
    ll tim;
    int way;//xl
};

node q[maxn>>5];
int hh,tt=1;
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>Q;
    g.resize(m+1);
    for(int i=1;i<=m;++i)cin>>w[i];
    for(int i=1;i<=n;++i){
        cin>>k[i];
        for(int j=1;j<=k[i];++j){
            cin>>a[i][j]>>t[i][j];
            g[a[i][j]].push_back(i);
        }
    }
    while(Q--){
        memset(timee,0x7f,sizeof(timee));
        hh=0;
        tt=1;
        int x,y;
        ll ans=1e18;
        cin>>x>>y;

        if(x==y){
            cout<<"0\n";
            continue;
        }
        q[hh].x=x;
        q[hh].tim=w[x];
        while(hh<tt){
            if(q[hh].x==y){
                ans=min(ans,q[hh].tim+w[y]);
                ++hh;
                continue;
            }
            for(int v:g[q[hh].x]){
                if(v==q[hh].way)continue;
                int b;
                for(int i=1;i<=k[v];++i)
                if(q[hh].x==a[v][i]){
                    b=i;
                    break;
                }
                for(int i=1;i<=k[v];++i){
                    ll cst=q[hh].tim+t[v][b]+t[v][i];
                    if((a[v][i]==y||g[a[v][i]].size()>1)&&a[v][i]!=q[hh].x)
                        if(timee[a[v][i]]>cst){
                            q[tt].x=a[v][i];
                            q[tt].tim=cst;
                            q[tt++].way=v;
                            timee[a[v][i]]=q[tt].tim;
                        }
                }
            ++hh;
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}
