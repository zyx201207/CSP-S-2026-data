#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
#define pii pair<int,int>
#define pb push_back
using namespace std;
const int N = 1e6+10,inf = 1e18;
int c,_,k,n;
vector<int> e[N];
struct sub1{
    int dis[N],vis[N],flag[N];
    void dfs(int u,int fa){
        for(auto v : e[u]){
            if(v==fa || !flag[v])    continue;
            flag[v]=0;
            dfs(v,u);
        }
    }
    void solve(){
        int S=(1<<n)-1,res=inf;
        for(int s = 0;s <= S;s ++){
            int maxn=0,cnt=0,sum=0;
            for(int i = 1;i <= n;i ++){
                dis[i]=inf;
                vis[i]=0;
                flag[i]=(s>>(i-1))&1;
                sum+=flag[i];
            }
            for(int i = 1;i <= n;i ++){
                if(flag[i]){
                    cnt++;
                    dfs(i,0);
                }
            }
            if(cnt>2 || sum!=k)   continue;
            queue<int> q;
            for(int i = 1;i <= n;i ++){
                if((s>>(i-1))&1){
                    q.push(i);
                    dis[i]=0,vis[i]=1;
                }
            }
            while(q.size()){
                int u=q.front();
                maxn=max(maxn,dis[u]);
                q.pop();
                for(auto v : e[u]){
                    if(dis[v]>dis[u]+1 && !vis[v]){
                        vis[v]=1;
                        dis[v]=dis[u]+1;
                        q.push(v);
                    }
                }
            }
            res=min(res,maxn);
        }
        cout << res << '\n';
    }
}sb1;
struct sub2{
    int dis[N],vis[N];
    bool check(int x){
        int m=n/2;
        int r=m+1-x,l=x;
        if(r<=l)    return true;
        queue<int> q;
        for(int i = 1;i <= n;i ++){
            dis[i]=inf;
            vis[i]=0;
        }
        q.push(r);
        dis[r]=0,vis[r]=1;
        for(int i = l,sum = 1;i < r && sum<k;i ++,sum ++){
            q.push(i);
            dis[i]=0,vis[i]=1;
        }
        int maxn=0;
        while(q.size()){
            int u=q.front();
            maxn=max(maxn,dis[u]);
            q.pop();
            for(auto v : e[u]){
                if(dis[v]>dis[u]+1 && !vis[v]){
                    vis[v]=1;
                    dis[v]=dis[u]+1;
                    q.push(v);
                }
            }
        }
        return (maxn<=x);
    }
    void solve(){
        int l=1,r=n/2,res=n/2;
        while(l<=r){
            int mid=(l+r)>>1;
            if(check(mid)){
                r=mid-1;
                res=mid;
            }else{
                l=mid+1;
            }
        }
        cout << res << '\n';
    }
}sb2;
struct sub3{
    int dep[N],f[N],dis[N],vis[N];
    pii maxn,maxn3;
    void dfs(int u,int fa){
        f[u]=fa;
        for(auto v : e[u]){
            if(v==fa)   continue;
            dep[v]=dep[u]+1;
            pii tmp={dep[v],v};
            maxn=max(maxn,tmp);
            dfs(v,u);
        }
    }
    queue<int> q;
    pii query(){
        pii maxn2={0,0};
        while(q.size()){
            int u=q.front();
            pii tmp={dis[u],u};
            maxn2=max(maxn2,tmp);
            q.pop();
            for(auto v : e[u]){
                if(dis[v]>dis[u]+1 && !vis[v]){
                    vis[v]=1;
                    dis[v]=dis[u]+1;
                    q.push(v);
                }
            }
        }
        return maxn2;
    }
    int lim;
    void dfs2(int u,int fa){
        for(auto v : e[u]){
            if(v==fa || v==lim)   continue;
            pii tmp={dep[v],v};
            maxn3=max(maxn3,tmp);
            dfs2(v,u);
        }
    }
    bool check(int x){
        int tmp=x,x1=maxn.second,x2=maxn3.second;
        cout << x << ' ' << x1 << ' ' << x2 << ' ';
        while(tmp--){
            x1=f[x1];
            x2=f[x2];
        }
        x1=max(x1,1ll),x2=max(x2,1ll);
        cout << x1 << ' ' << x2 << ' ';
        for(int i = 1;i <= n;i ++)  dis[i]=inf,vis[i]=0;
        dis[x1]=dis[x2]=0,vis[x1]=vis[x2]=1;
        q.push(x1);
        q.push(x2);
        pii kk=query();
        cout << kk.first << '\n';
        return (kk.first<=x);
    }
    void solve(){
        dep[1]=0;
        maxn=maxn3={0,0};
        dfs(1,0);
        lim=maxn.se;
        while(f[lim]!=1){
            lim=f[lim];
        }
        dfs2(1,0);
        int l=1,r=maxn.first-1,res=maxn.first;
        while(l<=r){
            int mid=(l+r)>>1;
            if(check(mid)){
                r=mid-1;
                res=mid;
            }else{
                l=mid+1;
            }
        }
        cout << res << '\n';
    }
}sb3;
signed main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin >> c >> _;
    while(_--){
        cin >> n >> k;
        for(int i = 1;i <= n;i ++){
            e[i].clear();
        }
        for(int i = 1;i < n;i ++){
            int u,v;
            cin >> u >> v;
            e[u].pb(v);
            e[v].pb(u);
        }
        if(k>=n)    cout << "0\n";
        if(c>=1 && c<=3)    sb1.solve();
        if(c>=13 && c<=14) sb2.solve();
        if(c==7 || c==11 || c==12)    sb3.solve();
    }
    return 0;
}