#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll c,t,n,k,u,v,cnt,v3;
ll dp[4001][4001],vis[4001],b[4001];
ll v1[4001],v2[4001];
ll s[4001];
vector<ll>q[4001];
void f(ll x,ll y,ll r,ll z){
    dp[x][y]=z;
    //cout<<x<<" "<<y<<" "<<z<<endl;
    cnt=max(cnt,z);
    for(ll i=0;i<q[y].size();i++){
        if(q[y][i]!=r){
            f(x,q[y][i],y,z+1);
        }
    }
    return;
}
ll check(ll x){
    ll e=0,w=0,o=0;
    for(int i=1;i<=n;i++){
        vis[v2[i]]=0;
    }
    while(e<n){
       o++;
       w=0;
       e=0;
       ll a1=0,b1=0;
       for(int i=1;i<=n;i++){
            if(vis[v2[i]]==0){
                w++;
                b[w]=v2[i];
            }
       }
       for(int i=1;i<=w;i++){
           for(int j=i+1;j<=w;j++){
               if(dp[b[i]][b[j]]<=x){
                    s[i]++;
                    s[j]++;
                    if(s[i]>a1){
                        a1=s[i];
                        b1=i;
                    }
                    if(s[j]>a1){
                        a1=s[j];
                        b1=j;
                    }
                }
            }
       }
       //cout<<x<<" "<<a1<<" "<<b[b1]<<endl;
       vis[b[b1]]++;
       for(int i=1;i<=n;i++){
           if(dp[v2[i]][b[b1]]<=x){
                vis[v2[i]]++;
           }
       }
       for(int i=1;i<=n;i++){
            if(vis[v2[i]]){
                e++;
            }
       }
    }
    //cout<<x<<" "<<o<<endl;
    if(o>k){
        return 1;
    }else{
        return 0;
    }
}
int main(){
    freopen("hub1.in","r",stdin);
    freopen("hub.out","w",stdout);
    scanf("%lld%lld",&c,&t);
    for(int i=1;i<=t;i++){
        scanf("%lld%lld",&n,&k);
        cnt=0;
        v3=0;
        for(int j=1;j<n;j++){
            scanf("%lld%lld",&u,&v);
            q[u].push_back(v);
            q[v].push_back(u);
            if(!v1[v]){
                v3++;
                v2[v3]=v;
            }
            if(!v1[u]){
                v3++;
                v2[v3]=u;
            }
        }
        for(int j=1;j<=n;j++){
            f(v2[j],v2[j],-1,0);
        }
        ll l=1,r=cnt,ans=0;
        //cout<<cnt<<endl;
        while(l<=r){
            ll mid=(l+r)/2;
            if(check(mid)){
                l=mid+1;
            }else{
                ans=mid;
                r=mid-1;
            }
            //cout<<ans<<" "<<mid<<endl;
        }
        //cout<<ans<<endl;
        printf("%lld\n",ans);
        for(int j=1;j<=n;j++){
            q[v2[j]].clear();
        }
    }
    return 0;
}
