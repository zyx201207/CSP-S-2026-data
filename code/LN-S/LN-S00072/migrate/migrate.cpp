#include<bits/stdc++.h>
#define EQ ==
using namespace std;
typedef long long ll;
const int N=2000200;
int n,num_l[N],num_r[N];
ll d,x[N],ans=0;
inline void work(int l,int r){
    if(r-l+1<4){
        return ;
    }
    ll x1=x[l],x2=x[l+1],x3=x[l+2],x4=x[l+3];
    int lst_l=0,nxt_r=r+1;
    for(int t=l+3;t<=r;t++){
        if(x4-x2<=d&&x3-x1<=d&&x4-x1>d){
            num_l[t]=(t-3-lst_l);lst_l=t-3;
        }
        x1=x2;x2=x3;x3=x4;x4=x[t+1];
    }
    x4=x[r];x3=x[r-1];x2=x[r-2];x1=x[r-3];
    for(int t=r;t>=l+3;t--){
        if(x4-x2<=d&&x3-x1<=d&&x4-x1>d){
            num_r[t]=(nxt_r-t);nxt_r=t;
            ans+=1ll*num_l[t]*num_r[t];
        }
        x4=x3;x3=x2;x2=x1;x1=x[t-4];
    }
}
inline void solve(){
    cin>>n>>d;ans=0;
    for(int t=1;t<=n;t++){
        cin>>x[t];
    }
    int l=1,r=0;
    for(int t=1;t<n;t++){
        if(x[t+1]-x[t]>d){
            r=t;work(l,r);
            l=t+1;
        }
    }
    r=n;work(l,r);
    cout<<ans<<'\n';
}
int main(){
    cin.tie(0)->ios::sync_with_stdio;
    cout.tie(0)->ios::sync_with_stdio;
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,T;cin>>c>>T;
    while(T--){
        solve();
    }
    return 0;
}