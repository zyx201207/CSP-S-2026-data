#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2000010;
const ll INF=1e18;
int c,t;
ll n,d,ans;
vector<ll>to[maxn];
ll x[maxn];

inline ll read(){
    ll s=0,f=1;
    char ch=getchar();
    while(ch<'0' || ch>'9'){
        if(ch=='-') f=-1;
        ch=getchar();
    }
    while(ch>='0' && ch<='9'){
        s=s*10+ch-'0';
        ch=getchar();
    }
    return s*f;
}

ll cnt[maxn],dis[maxn];
void dfs(int u,ll st){
    for(int i=u+1;i<=n;i++){
        if(x[i]-x[u]>d) break;
        if(st<dis[i]){
            dis[i]=st;
            cnt[i]=1;
        }
        else if(st==dis[i]){
            cnt[i]++;
        }
        dfs(i,st+1);
    }
}

int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    c=read(),t=read();
    while(t--){
        ans=0;
        n=read(),d=read();
        for(int i=1;i<=n;i++){
            x[i]=read();
        }
        for(int i=1;i<n;i++){
            for(int j=i+1;j<=n;j++) dis[j]=INF;
            dis[i]=0;
            dfs(i,0);
            for(int j=i+1;j<=n;j++){
                if(cnt[j]==2) ans++;
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}
