#include<bits/stdc++.h>
#define  ll long long
using namespace std;
ll read(){
    ll x=0,f=1;char c=getchar();
    while(!isdigit(c)&&c!='-') c=getchar();
    if(c=='-') f=-1;
    while(!isdigit(c)) c=getchar();
    while(isdigit(c)){
        x=x*10+c-'0';
        c=getchar();
    }
    return f*x;
}
const ll N=2e6+10;
ll c,T,n,d,x[N];
ll findrx(ll u,ll ed){
    ll l=u,r=ed,s=u;
    while(l<=r){
        ll mid=(l+r)>>1;
        if(x[mid]-x[u]<=d){
            l=mid+1;s=mid;
        }
        else r=mid-1;
    }
    return s;
}
ll minn[N],num[N];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    c=read();T=read();
    while(T--){
        n=read();d=read();
        for(ll i=1;i<=n;i++) x[i]=read();
        if(c==11||c==12){
            ll dd=x[2]-x[1];
            if(dd>d) cout<<0<<endl;
            else{
                ll ans=0,k=d/dd;
                if(k==1){
                    cout<<0<<endl;
                    continue;
                }
                ans=ans+(n-2*k+1);
                printf("%lld\n",max(ans,0ll));
            }
            continue;
        }
        ll ans=0;
        for(ll i=3;i<=n;i++){
            for(ll j=1;j<=i-1;j++) num[j]=0;
            num[i]=1;ll lst=i;
            for(ll j=i-1;j>=1;j--){
                ll rx=findrx(j,lst);
                //cout<<j<<" "<<i<<"!"<<rx<<endl;
                minn[j]=minn[rx]+1;
                ll tot=num[rx];
                if(minn[rx-1]==minn[rx]) tot=tot+num[rx-1];
                if(minn[rx-2]==minn[rx]) tot=tot+num[rx-2];
                if(tot==2) ans++;
                num[j]=tot;
                lst=rx;
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}