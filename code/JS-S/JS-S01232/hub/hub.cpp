#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
#define repa(i,a,b) for(int i=(a);i<(b);++i)
#define pr(x) cout<<__LINE__ << #x << x<<endl
#define P 998244353
// #define P 1000000007
#define maxn 1000005
vector<int>a[maxn],ans[maxn];
int b[maxn],c[maxn],d[maxn],f[maxn];
int dfs1(int x,int fa){
    d[x]=d[fa]+1;
    f[x]=fa;
    int ret=x;
    for(int y:a[x]){
        if(y==fa)continue;
        int t=dfs1(y,x);
        if(d[ret]<d[t])ret=t;
    }
    c[x]=d[ret]-d[x];
    return ret;
}
int dfs(int x,int son,int now){
    int ret=0;
    for(int y:a[x]){
        if(y==f[x]||y==son)continue;
        ret=max(ret,dfs(y,son,now)+1);
    }
    if(x==now)return ret;
    if(ans[now].size()<=ret)ans[now].push_back(1);
    else ans[now][ret]++;
    return ret;
}
int m;
int dp[maxn][2];
bool check(int v,int rt1,int rt2){
    int now=rt2;
    rep(i,1,v)now=f[now];
    vector<int>p;
    while(d[now]>v){
        // pr(a[now].size());
        if(ans[now].size()>v)p.push_back(ans[now][v]);
        else p.push_back(ans[now].size()-v);
        now=f[now];
    }
    int sz=p.size();
    if(sz==0)return 1;
    dp[0][0]=max(0,p[0])+1;
    repa(i,1,sz){
        dp[i][0]=dp[i-1][0]+max(0,p[i])+1;
    }
    dp[sz-1][1]=p[sz-1]+1;
    per(i,sz-2,0){
        dp[i][1]=dp[i+1][1]+max(0,p[i])+1;
    }
    int ret=dp[sz-1][0];
    int x=0,y=sz-1;
    repa(i,-1,sz){
        rep(j,i+1,sz){
            bool f=1;
            rep(k,i+1,j-1){
                if(p[k]+min(k-i,j-k)>=0)f=0;
            }
            if(!f)continue;
            ret=min(ret,(i>=0?dp[i][0]:0)+(j<sz?dp[j][1]:0));
        }
        // now=max(now,i+1);
        // while(p[now]+)
        // while(now+1<sz&&p[now]+min(now-i,sz-(m-i-1)-now)<=0)now++;
        // ret=min(ret,dp[i][0]+dp[now][1]);
        // i=now-1;
    }
    // pr(v);pr(ret);
    return ret<=m;
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int C,T;cin>>C>>T;
    while(T--){
        int n;cin>>n>>m;
        rep(i,1,n)a[i].clear();
        repa(i,1,n){
            int x,y;
            cin>>x>>y;
            a[x].push_back(y);
            a[y].push_back(x);
        }
        int rt1=dfs1(1,0);
        int rt2=dfs1(rt1,0);
        // pr(rt1);pr(rt2);
        int now=rt2;
        while(now!=rt1){
            int son=now;
            now=f[now];
            ans[now].clear();
            dfs(now,son,now);
            per(i,ans[now].size()-2,0)ans[now][i]+=ans[now][i+1];
        }
        int l=0,r=n;
        while(l+1<r){
            int mid=l+r>>1;
            if(check(mid,rt1,rt2))r=mid;
            else l=mid;
        }
        cout<<r<<endl;
    }
}