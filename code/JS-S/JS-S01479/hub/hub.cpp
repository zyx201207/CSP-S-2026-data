#include <bits/stdc++.h>
using namespace std;
#define int long long
#define F(i, a, b) for (int i = (a); i <= (b); i ++ )
#define DF(i, a, b) for (int i = (a); i >= (b); i -- )
inline void chkmin(int& a, int b) { if (a > b) a = b; }
inline void chkmax(int& a, int b) { if (a < b) a = b; }

typedef pair<int,int> PII;

const int N = 4010;
const int INF = 1e18;

int n,k,h[N],e[N],ne[N],idx;
int eu[N],ev[N];
int id;
int depth[N];
int dist[N][N];
int require;

void add(int a,int b){
    e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}

vector<int> nodes;

void dfs(int u,int father){
    nodes.push_back(u);
    for(int i=h[u];~i;i=ne[i]) {
        int j=e[i];
        if(j==father||u==eu[id]&&j==ev[id]||u==ev[id]&&j==eu[id]) continue;
        dfs(j,u);
    }
}
void dp(int u,int father){
    depth[u]=0;
    for(int i=h[u];~i;i=ne[i]) {
        int j=e[i];
        if(j==father||u==eu[id]&&j==ev[id]||u==ev[id]&&j==eu[id]) continue;
        // if(id==1&&require==0)cout<<u<<" -> "<<j<<"\n";
        dp(j,u);
        chkmax(depth[u],depth[j]+1);
    }
}

int work(int rt,int f) {
    nodes.clear();
    dfs(rt,-1);
    int mn=1e18;
    for(auto i:nodes) {
        dp(i,-1);
        // if(id==1&&require==0) {
        //     cout<<"root = "<<i<<", depth: ";
        //     F(k,1,n) cout<<depth[k]<<" ";cout<<"\n";
        // }
        int sum=0;
        for(auto k:nodes) sum+=depth[k] >= require;
        chkmin(mn,max(sum,1LL));
    } 
    // if(id==1&&require==0) {
    //     cout<<"rt : "<<rt<<"\n";
    //     cout<<"nodes: ";
    //     for(auto i:nodes)cout<<i<<" ";cout<<"\n";
    //     cout<<"mn = "<<mn<<"\n";
    // }
    // if(f==1&&require==0) {
    //     cout<<"nodes.size() = "<<nodes.size()<<"\n";
    // }
    return mn;
}

int work() {
    int t = work(eu[id],0) + work(ev[id],0);
    // if(require==0&&t<=k) {
    //     work(eu[id],1);
    //     work(ev[id],1);
    //     cout<<"left = "<<work(eu[id],1)<<", right = "<<work(ev[id],1)<<"\n";
    //     exit(0);
    // }
    return t;
}

bool check(int mid) {
    require=mid;
    id=0;
    if(work()<=k) {
        // if(require==0) cout << "!!!!!!!"<<endl;
        return 1;
    }
    F(i,1,n-1) {
        id=i;
if(work()<=k) {
    // if(require==0) cout <<"!! edge "<<id<<endl;
    return 1;
}
    }
    // cout<<"check fail"<<endl;
    return 0;
}
void solve() {
    cin >> n >> k;
    F(i,1,n) h[i]=-1; idx=0;
    F(i,1,n-1) cin>>eu[i]>>ev[i],add(eu[i],ev[i]),add(ev[i],eu[i]);
    int l=0,r=n,res=n;
    while(l<=r) {
        int mid=l+r>>1;
        if(check(mid)) res=mid,r=mid-1;
        else l=mid+1;
    }
    cout<<res<<"\n";
}

signed main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    // ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int c, te;cin>>c>>te;
    while(te--) solve();
    return 0;
}