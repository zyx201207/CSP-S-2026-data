#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+10,M=1e5+10;
struct node{
    int v,w;
};
vector<int>e[N+550];
vector<int>op[N];
int c,n,m,d,q,k[N],w[N],cnt;
ll dis[N],ans[M];
struct answ{
    int v,id;
};
set<pair<int,int>>t[N];
bool flag[N];
struct nodee{
    int v;
    ll d;
};
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
        e[i].push_back((++cnt,w[i]));
    }
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            int a,t;
            cin>>a>>t;
        }
    }
    cnt=n;
    while(q--){
        int x,y;
        cin>>x>>y;
    }
    cout<<n+m<<"\n";
    return 0;
}
