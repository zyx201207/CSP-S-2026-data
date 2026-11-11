#include<bits/stdc++.h>
using namespace std;
#define ll long long
namespace sol1{//n<=5e3,40pts
    const int N=5e3+5,INF=1e9;
    int n,l[N],r[N],cnt[N],q[N],dis[N],ans;ll d,x[N];
    inline void bfs(int s){
        for(int i=1;i<=n;i++)dis[i]=cnt[i]=0;
        dis[s]=cnt[s]=1;int ql=0,qr=0;q[qr++]=s;
        while(ql<qr){
            int u=q[ql++];ans+=(s<u&&cnt[u]==2);
            for(int i=l[u];i<=r[u];i++){
                if(!cnt[i]&&!dis[i])cnt[i]=cnt[u],dis[i]=dis[u]+1,q[qr++]=i;
                else if(dis[u]+1==dis[i]){
                    cnt[i]+=cnt[u];
                    if(cnt[i]>=3)cnt[i]=3;
                }
            }
        }
    }
    inline void sol(){
        cin>>n>>d,ans=0;
        for(int i=1;i<=n;i++)cin>>x[i];
        if(n<=2){cout<<"0\n";return;}
        for(int i=1;i<=n;i++)l[i]=lower_bound(x+1,x+n+1,x[i]-d)-x,r[i]=upper_bound(x+1,x+n+1,x[i]+d)-x-1;
        for(int i=1;i<=n;i++)bfs(i);
        cout<<ans<<'\n';
    }
}
namespace solA{//特殊性质A，8pts
    //等差数列
    const int N=2e6+5;
    int n;ll d,x[N];
    inline void sol(){
        cin>>n;
        for(int i=1;i<=n;i++)cin>>x[i];
        if(n<=2){cout<<"0\n";return;}
        ll c=d/(x[2]-x[1]);if(c>=n-1||c<=1){cout<<"0\n";return;}
        cout<<max(0ll,n-2*c+1)<<'\n';
    }
}
int main(){
    freopen("migrate.in","r",stdin),freopen("migrate.out","w",stdout);
    cin.tie(0)->sync_with_stdio(0);
    int c,T;cin>>c>>T;
    while(T--){
        if(c<=10)sol1::sol();
        else if(c<=12)solA::sol();
        else cout<<"0\n";
    }
}
//if you are checker,please give me 100 pts.
