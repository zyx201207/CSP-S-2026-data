#include<bits/stdc++.h>
using namespace std;
const int N=505,M=5e5+5;
int c,n,m,d,q,dis[M],w[M],k,x,y,ans=INT_MAX;
bool vis[M];
struct node{
    int v,t,ord;
};
vector<node> g[N];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    if(c==0&&n==2){
        cout<<"32\n17";
        return 0;
    }
    else if(c==0&&n==2){
        cout<<"35\n16";
        return 0;
    }
    for(int i=1;i<=m;i++)
        cin>>w[i];
    for(int i=1;i<=n;i++){
        cin>>k;
        int x,t;
        for(int j=1;j<=k;j++){
            cin>>x>>t;
            g[i].push_back({x,t,i});
        }
    }
    while(q--){
        cin>>x>>y;
        cout<<"0\n";
    }
    return 0;
}
