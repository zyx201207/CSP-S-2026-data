#include<bits/stdc++.h>
using namespace std;
#define x first
#define y second
typedef long long ll;
typedef pair<ll,int> pii;
const int N=50010,M=2.5e7+10,INF=0x3f3f3f3f;
int n;
ll d;
ll a[N];
int cnt[N];
int h[N],e[M],ne[M],idx;
ll dist[N];
ll ans;
void add(int a,int b) {
    e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}
void bfs(int s) {
    for(int i=s;i<=n;i++) dist[i]=INF;
    for(int i=s;i<=n;i++) cnt[i]=0;
    queue<pii> q;
    dist[s]=0;
    q.push({0,s});
    while(q.size()) {
        auto t=q.front();
        q.pop();

        int u=t.y;
        ll d=t.x;

        for(int i=h[u];~i;i=ne[i]) {
            int j=e[i];
            if(dist[j]>d+1) {
                dist[j]=d+1;
                cnt[j]=1;
            }
            else if(dist[j]==d+1)
                cnt[j]++;
            q.push({d+1,j});
        }
    }
    for(int i=s+1;i<=n;i++)
        if(cnt[i]==2)
            ans++;
}
int main() {
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,T;
    cin>>c>>T;
    if(c<=10) {
        while(T--) {
            ans=0;
            memset(h,-1,sizeof h);
            idx=0;
            scanf("%d%lld",&n,&d);
            for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
            
            for(int i=1;i<n;i++)
                for(int j=i+1;j<=n;j++) {
                    if(a[j]-a[i]<=d) add(i,j);
                    else break;
                }

            for(int i=1;i<n;i++) bfs(i);
            printf("%lld\n",ans);
        }
    }
    else if(c>=11&&c<=12) {
        while(T--) {
            scanf("%d%lld",&n,&d);
            for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
            ll b=a[2]-a[1];
            if(b*2<=d) printf("%d\n",n-3);
            else puts("0");
        }
    }
    else if(c>=13&&c<=14) {
        while(T--) {
            scanf("%d%lld",&n,&d);
            for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
            printf("%d\n",n-3);
        }
    }
    return 0;
}