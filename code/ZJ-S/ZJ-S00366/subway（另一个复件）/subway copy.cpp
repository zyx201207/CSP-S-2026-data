#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;
namespace YuJH{
    int n,m,d,q;
    long long w[500010];
    int k[510];
    vector<int> a[510];
    vector<long long> t[510];
    struct Node{
        int b;
        long long t;
    };
    vector<Node> s[500010];
    long long G[510][510];
    long long ans;
    int main(){
        cin>>n>>m>>d>>q;
        for(int i=1;i<=m;i++)
            cin>>w[i];
        for(int i=1;i<=n;i++){
            cin>>k[i];
            a[i].resize(k[i]+1);
            t[i].resize(k[i]+1);
            for(int j=1;j<=k[i];j++){
                cin>>a[i][j]>>t[i][j];
                s[a[i][j]].push_back({i,t[i][j]});
            }
        }
        memset(G,0x3f,sizeof(G));
        for(int i=1;i<=n;i++){
            G[i][i]=0;
            for(int j=1;j<=k[i];j++)
                for(Node l:s[a[i][j]])
                    if(l.b!=i)
                        G[i][l.b]=min(t[i][j]+l.t,G[i][l.b]);
        }
        for(int k=1;k<=n;k++)
            for(int i=1;i<=n;i++)
                for(int j=1;j<=n;j++)
                    G[i][j]=min(G[i][k]+G[k][j],G[i][j]);
        for(int x,y;q--;){
            cin>>x>>y;
            ans=1e18;
            for(Node i:s[x])
                for(Node j:s[y])
                    ans=min(i.t+G[i.b][j.b]+j.t,ans);
            cout<<w[x]+ans+w[y]<<'\n';
        }
        return 0;
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int C;
    cin>>C;
    YuJH::main();
    return 0;
}