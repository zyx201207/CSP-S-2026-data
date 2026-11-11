#include<bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
const int MAXN=1e6+10;
vector<int>vec[MAXN];
int n,k;
namespace sub{
    bool ck(int x){
        int m=n/2;
        for(int i=1;i<=m;i++){
            int r=m+1-x;
            int len=max(1,r-i+1);
            int c=i-(x-1);
            int p=2*c-i;
            int A=x;
            if(max(1,p-A+1)+len<=k) return 1;
        }return 0;
    }
    void main(){
        int l=1,r=n,num=n;
        while(l<=r){
            int mid=l+r>>1;
            if(ck(mid)) num=mid,r=mid-1;
            else l=mid+1;
        }cout<<num<<'\n';
    }
}
namespace sub1{
    int d[MAXN];
    int vis[MAXN],ok[MAXN],mn;
    void bfs(){
        queue<int>q;
        for(int i=1;i<=n;i++) ok[i]=d[i]=0;
        for(int i=1;i<=n;i++) if(vis[i]==1) q.push(i),ok[i]=1;
        while(q.size()){
            int fr=q.front();q.pop();
            for(int to:vec[fr]){
                if(ok[to]) continue;
                d[to]=d[fr]+1;ok[to]=1;
                q.push(to);
            }
        }
    }
    int fa[MAXN];
    int find(int x){
        return (fa[x]==x?x:(fa[x]=find(fa[x])));
    }
    void dfs(int now,int cnt){
        if(cnt>k) return ;
        if(now==n+1){
            if(cnt!=k) return ;
            for(int i=1;i<=n;i++) fa[i]=i;
            for(int i=1;i<=n;i++){
                for(int to:vec[i]){
                    if(vis[to]&&vis[i]) fa[find(i)]=find(to);
                }
            }int sum=0;
            for(int i=1;i<=n;i++){
                if(vis[i]&&(find(i)==i)) ++sum;
            }if(sum>2) return ;
            bfs();int rs=0;
            for(int i=1;i<=n;i++) rs=max(rs,d[i]);
            mn=min(mn,rs);
            return ;
        }
        vis[now]=1;dfs(now+1,cnt+1);
        vis[now]=0;dfs(now+1,cnt);
    }
    void main(){
        mn=2e9;dfs(1,0);
        cout<<mn<<'\n';
    }
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int c,T;cin>>c>>T;
    while(T--){
        cin>>n>>k;
        for(int i=1;i<n;i++){
            int u,v;cin>>u>>v;
            vec[u].push_back(v);
            vec[v].push_back(u);
        }
        if(n==k) cout<<0<<'\n';
        else{
            if(c>=13&&c<=14) sub::main();
            else sub1::main(); 
        }
        for(int i=1;i<=n;i++) vec[i].clear();
    }
    return 0;
}