#include<bits/stdc++.h>
#define x first// ds or t
#define y second// u
using namespace std;
const int N=5e7+10,M=5e5+10;
vector<pair<int,int>>g[N];
long long ds[N];
int c,n,m,d,q,idx;
int w[N],a[M],t[M];
void add(int a,int b,int c){
    g[a].push_back({c,b});
}
bitset<N>vs;
void dij(int s){
    for(int i=0;i<=idx;i++){
        ds[i]=2e18;
    }
    vs.reset();
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
    ds[s]=0;
    q.push({0,s});
    while(q.size()){
        auto t=q.top();
        q.pop();
        if(vs[t.y])continue;
        vs[t.y]=1;
        for(auto oo:g[t.y]){
            int j=oo.y,w=oo.x;
            if(ds[j]>ds[t.y]+w){
                ds[j]=ds[t.y]+w;
                q.push({ds[j],j});
            }
        }
    }
}
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
        add(i,i+m,w[i]);
        add(i+m,i,w[i]);
    }
    idx=2*m;
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        for(int i=1;i<=k;i++){
            cin>>a[i]>>t[i];
            add(a[i]+idx,a[i]+m,t[i]);
            add(a[i]+m,a[i]+idx,t[i]);
        }
        for(int i=2;i<=k;i++){
            add(a[i]+idx,a[i-1]+idx,0);
            add(a[i-1]+idx,a[i]+idx,0);
        }
        idx+=m;
    }
    /*
    for(int i=1;i<=idx;i++){
        for(auto oo:g[i]){
            cout<<i<<"->"<<oo.y<<" "<<oo.x<<"\n";
        }
    }
    */
    while(q--){
        int x,y;
        cin>>x>>y;
        dij(x);
        cout<<ds[y]<<"\n";
    }

    return 0;
}
