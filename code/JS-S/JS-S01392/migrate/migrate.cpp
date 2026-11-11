#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll MAXN=2e6+10;
const ll inf=1e9;
ll c,t,n,d,x[MAXN],dis[MAXN],sum[MAXN];
struct DIS{
    #define ls u<<1
    #define rs u<<1|1
    #define mid ((l+r)>>1)
    ll Min[MAXN*4],val[MAXN*4];
    void init(ll x){
        for(ll i=1;i<=n*4;i++) Min[i]=x,val[i]=0;
    }
    void updmin(ll u,ll l,ll r,ll x,ll k){
        if(l==r){Min[u]=k;return;}
        if(x<=mid) updmin(ls,l,mid,x,k);
        else updmin(rs,mid+1,r,x,k); 
        Min[u]=min(Min[ls],Min[rs]);
    }
    void updval(ll u,ll l,ll r,ll x,ll k){
        if(l==r){val[u]=k;return;}
        if(x<=mid) updval(ls,l,mid,x,k);
        else updval(rs,mid+1,r,x,k); 
        val[u]=val[ls]+val[rs];
    }
    ll qryval(ll u,ll l,ll r,ll ql,ll qr){
        if(ql>qr) return 0;
        if(ql<=l&&r<=qr) return val[u];
        ll ans=0;
        if(ql<=mid) ans+=qryval(ls,l,mid,ql,qr);
        if(mid+1<=qr) ans+=qryval(rs,mid+1,r,ql,qr);
        return ans; 
    }
    ll qrymin(ll u,ll l,ll r,ll ql,ll qr){
        if(ql>qr) return inf;
        if(ql<=l&&r<=qr) return Min[u];
        ll ans=inf;
        if(ql<=mid) ans=min(ans,qrymin(ls,l,mid,ql,qr));
        if(mid+1<=qr) ans=min(ans,qrymin(rs,mid+1,r,ql,qr));
        return ans; 
    }
    ll qryr(ll u,ll l,ll r,ll x){
        if(l==r) return l;
        if(Min[rs]<=x) return qryr(rs,mid+1,r,x);
        else return qryr(ls,l,mid,x);
    }
}D;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    for(cin>>c>>t;t;t--){
        cin>>n>>d;
        for(ll i=1;i<=n;i++) cin>>x[i];
        if(c<=6){
            ll ans=0;
            for(ll i=1;i<=n;i++){
                for(ll j=1;j<=n;j++) dis[j]=inf,sum[j]=0;
                dis[i]=0;sum[i]=1;
                ll p=i;
                for(ll j=i+1;j<=n;j++){
                    while(p<j&&x[p]+d<x[j]) p++;
                    for(ll k=p;k<=j;k++) dis[j]=min(dis[j],dis[k]+1);
                    for(ll k=p;k<=j;k++) sum[j]+=(dis[k]==dis[j]-1)*sum[k];
                    if(sum[j]==2) ans++;
                }
            }
            cout<<ans<<"\n";
            continue;
        }
        if(c<=25){
            ll ans=0;
            for(ll i=1;i<=n;i++){
                D.init(inf);D.updmin(1,1,n,i,0);D.updval(1,1,n,i,1);
                for(ll j=1;j<=n;j++) dis[j]=inf,sum[j]=0;
                dis[i]=0;sum[i]=1;
                ll p=i;
                for(ll j=i+1;j<=n;j++){
                    while(p<j&&x[p]+d<x[j]) p++;
                    dis[j]=D.qrymin(1,1,n,p,j-1)+1;
                    D.updmin(1,1,n,j,dis[j]);
                    if(dis[j]>n) break;
                    ll q=D.qryr(1,1,n,dis[j]-1);
                    sum[j]=D.qryval(1,1,n,p,q);
                    D.updval(1,1,n,j,sum[j]);
                    if(sum[j]==2) ans++;
                    //cout<<i<<" "<<j<<" "<<p<<" "<<q<<" "<<dis[j]<<" "<<sum[j]<<"\n";
                }
            }
            cout<<ans<<"\n";
            continue;
        }
        // if(c==13||c==14){
        //     ll p=-1;
        //     for(ll i=1;i<=n;i++){
        //         if(x[n]-x[i]<=d&&x[i]-x[1]<=d){p=i;break;}
        //     }
        //     ll ans=p*(p-1)/2+(n-p+1)*(n-p)/2;
        //     for(int i=1,j=p+1;i<p&&j<=n;i++){
        //         while(x[j]-x[p]<=d-x[p]+x[i]) j++;
        //         ans+=j-p-1;
        //     }
        //     cout<<ans<<"\n";
        //     continue;
        // }
    }
    return 0;
}