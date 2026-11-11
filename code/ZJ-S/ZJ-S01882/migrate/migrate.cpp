#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e6+9;const ll inf=4e18;
int c,t,n,lst[N],nxt[N],cnt[N];ll x[N],sc[N],d;
int main(){
    freopen("migrate.in","r",stdin),freopen("migrate.out","w",stdout);
    for(cin>>c>>t;t--;){
        cin>>n>>d;
        for(int i=1;i<=n;i++)cin>>x[i];
        ll dd=x[2]-x[1],f=1;
        for(int i=2;i<=n;i++)if(x[i]-x[i-1]!=dd)f=0;
        if(f){//A
            ll k=d/dd;
            cout<<(k>=2?max(n-2*k+1,0ll):0)<<'\n';
        }else{
            for(int i=1;i<=n;i++)lst[i]=upper_bound(x+1,x+n+1,x[i]-d-1)-x,nxt[i]=upper_bound(x+1,x+n+1,x[i]+d)-x-1;
            lst[1]=0,nxt[n]=n;
            //for(int i=1;i<=n;i++)cerr<<lst[i]<<' '<<nxt[i]<<'\n';
            ll ans=0;
            for(int i=1;i<=n;i++){
                for(int j=i;j<=nxt[i];j++)sc[j]=sc[j-1]+(cnt[j]=1);
                for(int j=nxt[i];j<=n&&j!=nxt[j];j=nxt[j]){
                    for(int k=j+1;k<=nxt[j];k++){
                        sc[k]=sc[k-1]+(cnt[k]=sc[j]-sc[lst[k]-1]);
                        if(cnt[k]==2)++ans;//cerr<<i<<' '<<k<<'\n';
                    }
                }for(int j=i;j<=n;j++)sc[j]=cnt[j]=0;
            }cout<<ans<<'\n';
            for(int i=1;i<=n;i++)lst[i]=nxt[i]=0;
        }
        
    }
    return 0;
}/*
0 1
10 3
0 3 6 7 8 9 10 11 14 17
*/