#define ll long long
#include<bits/stdc++.h>
using namespace std;
const int N=2000010;

int n,k,ans;
int b[N],d[N],c[N];
vector<int>e[N];

void dfs(int x,int sum){
    if(x==n+1){
        if(sum!=k) return;
        int cnt=0;
        for(int i=1;i<=n;i++) d[i]=0;
        for(int i=1;i<=n;i++) if(b[i]==1&&d[i]==0){
            d[i]=++cnt;
            queue<int>q;q.push(i);
            while(!q.empty()){
                int x=q.front();q.pop();
                for(auto u:e[x]) if(b[u]==1&&d[u]==0) d[u]=cnt,q.push(u);
            }
        }
        if(cnt>2) return;
        for(int i=1;i<=n;i++) c[i]=INT_MAX;
        queue<int>q;
        for(int i=1;i<=n;i++) if(b[i]==1) q.push(i),c[i]=0;
        while(!q.empty()){
            int x=q.front();q.pop();
            for(auto u:e[x]) if(c[u]==INT_MAX) c[u]=c[x]+1,q.push(u);
        }
        int mx=-1;
        for(int i=1;i<=n;i++) mx=max(mx,c[i]);
        ans=min(ans,mx);
        return;
    }
    b[x]=0;
    dfs(x+1,sum);
    b[x]=1;
    dfs(x+1,sum+1);
}

void solve(){
    cin>>n>>k;
    for(int i=1;i<=n;i++) e[i].clear();
    for(int i=1,x,y;i<n;i++) cin>>x>>y,e[x].push_back(y),e[y].push_back(x);
    ans=INT_MAX;
    dfs(1,0);
    cout<<ans<<"\n";
}

int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t=1;
    int c;
    cin>>c>>t;
    while(t--)solve();
}
