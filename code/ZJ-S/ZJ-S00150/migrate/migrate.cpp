#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<ll,ll> 
#define fi first
#define se second
const ll N=2e6+10,M=5050;
ll c,T,n,d,x[N],l,r,ans;
int pl[N],pr[N],dis[N],cnt[N];
void bfs(ll s){
    for(int i=1;i<=n;i++) dis[i]=-1,cnt[i]=0;
    queue<pii> q;q.push({s,0});
    while(!q.empty()){
        ll x=q.front().fi,st=q.front().se;q.pop();
        if(dis[x]!=-1&&dis[x]<st) continue;
        dis[x]=st,cnt[x]++;
        if(cnt[x]>3) continue;
        for(int y=pl[x];y<=pr[x];y++)
            q.push({y,st+1});
    }
}
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>T;
    if(c==4){
        while(T--){
            cin>>n>>d;
            for(int i=1;i<=n;i++) cin>>x[i];
            if(n==1||d<=x[2]-x[1]){cout<<"0\n";continue;}
            cout<<max(0ll,n-2*(d/(x[2]-x[1]))+1)<<"\n";
        }
        return 0;
    }
    while(T--){
        cin>>n>>d;
        for(int i=1;i<=n;i++) cin>>x[i];
        l=r=1;ans=0;
        for(int i=1;i<=n;i++){
            while(l>1&&x[i]-x[l-1]<=d) l--;
            while(r<n&&x[r+1]-x[i]<=d) r++;
            pl[i]=l,pr[i]=r;
        }
        for(int i=1;i<=n;i++){
            bfs(i);
            for(int j=1;j<=n;j++)
                if(cnt[j]==2) ans++;
        }
        cout<<ans<<"\n";
    }
    return 0;
}