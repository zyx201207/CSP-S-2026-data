#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn=1e5+10;
int n,f[maxn],cnt[maxn];
ll d,x[maxn];
void work(){
    scanf("%d%lld",&n,&d);
    for(int i=1;i<=n;i++){
        scanf("%lld",&x[i]);
    }
    ll ans=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++) f[j]=-1;
        queue<pair<int,int> >q;
        q.push({i,0});
        while(!q.empty()){
            int nw=q.front().first,dis=q.front().second;
            q.pop();
            if(f[nw]==-1){
                f[nw]=dis;
                cnt[nw]=1;
            }
            else if(dis==f[nw]) cnt[nw]++;
            else continue;
            for(int j=nw+1;j<=n&&(x[j]-x[nw])<=d;j++){
                q.push({j,dis+1});
            }
        }
        for(int j=i+1;j<=n;j++){
            if(cnt[j]==2) ans++;
        }
    }
    printf("%lld\n",ans);
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    scanf("%d%d",&c,&t);
    while(t--){
        work();
    }
}