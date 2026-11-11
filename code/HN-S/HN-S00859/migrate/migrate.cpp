#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+5;
int f[N],g[N],c,t,n,d,x[N],ff[N],gg[N];
bool flag;
void solve(){
    cin >> n >> d;
    for(int i=1;i<=n;i++){
        cin >> x[i];
    }
    if(flag){
        int cnt=0;
        for(int i=1;i<=n;i++){
            if(x[i]-d<=x[1]&&x[i]+d>=x[n]){
                cnt++;
            }
        }
        if(cnt>=3){
            cout << "0\n";
            return ;
        }
        if(cnt==1){
        int id=0;
            for(int i=1;i<=n;i++){
                if(x[i]-d<=x[1]&&x[i]+d>=x[n]){
                    id=i;
                }
            }
            int lt=0,rt=0;
            for(int i=1;i<=n;i++){
                if(x[i]+d<x[id+1])lt++;
                if(x[i]-d>x[id-2]&&x[i]-d<=x[id-1])rt++;
            }
            int ans=lt*rt;
            lt=rt=0;
            for(int i=1;i<=n;i++){
                if(x[i]+d<x[id+2]&&x[i]+d>=x[id+1])lt++;
                if(x[i]-d>x[id-1])rt++;
            }
            ans+=lt*rt;
            cout << ans << '\n';
            return ;
        }
        int id;
            for(int i=1;i<=n;i++){
                if(x[i]-d<=x[1]&&x[i]+d>=x[n]){
                    id=i;
                    break;
                }
            }
            int lt=0,rt=0;
            for(int i=1;i<=n;i++){
                if(x[i]+d<x[id+2])lt++;
                if(x[i]-d>x[id-1])rt++;
            }
            cout << lt*rt<<'\n';
            return ;    
    }
    for(int i=0;i<n+2;i++)f[i]=g[i]=ff[i]=gg[i]=0;
    f[1]=1;
    x[0]=-2e18;
    for(int i=1;i<n;i++){
        int lt=lower_bound(x+1,x+1+n,x[i]-d)-x;
        int rt=lower_bound(x+1,x+1+n,x[i+1]-d)-x-1;
        // cerr<<lt<<' '<<rt<<' '<<x[i]-d<<' '<<x[i+1]-d<<'\n';
        if(rt==0){
            f[i]=1;
            continue;
        }
        if(lt==rt){
            f[i]=f[lt]+1;
        }else{
            f[i]=(rt-lt+2);
        }
    }
    // for(int i=1;i<=n;i++){
    //     cout << f[i] << ' ';
    // }
    // cout << '\n';
    for(int i=1;i<=n;i++)
        ff[i]=ff[i-1]+f[i];
    g[n]=1;
    x[n+1]=2e18;
    for(int i=n;i;i--){
        int lt=upper_bound(x+1,x+2+n,x[i-1]+d)-x;
        int rt=upper_bound(x+1,x+2+n,x[i]+d)-x-1;
        // cerr<<lt<<' '<<rt<<'\n';
        if(lt==n+1){
            g[i]=1;
            continue;
        }
        if(lt==rt){
            g[i]=g[lt]+1;
        }else{
            g[i]=(rt-lt+2);
        }
        // cerr<<x[i-1]+d<<' ';
    }
    // for(int i=1;i<=n;i++){
    //     cout << g[i] << ' ';
    // }
    // cout << '\n';
    for(int i=n;i;i--)
        gg[i]=gg[i+1]+g[i];
    int ans=0;
    for(int i=3;i<n;i++){
        int lls=lower_bound(x+1,x+1+n,x[i-1]-d)-x;
        int llt=lower_bound(x+1,x+1+n,x[i]-d)-x;
        int lrt=lower_bound(x+1,x+1+n,x[i+1]-d)-x-1;
        int rlt=upper_bound(x+1,x+2+n,x[i-1-1]+d)-x;
        int rrt=upper_bound(x+1,x+2+n,x[i-1]+d)-x-1;
        int rrs=upper_bound(x+1,x+1+n,x[i]+d)-x-1;
        if(lrt>=i-1)lrt=i-2;
        if(rlt<=i)rlt=i+1;
        if(llt>lrt||rlt>rrt)continue;
        // cout <<llt << ' ' << lrt << ' ' << rlt << ' ' << rrt << '\n';
        // cout << x[i]-d <<' '<< x[i+1]-d << ' ' << x[i-1-1]+d <<' '<< x[i-1]+d << '\n';
        // cout << f[llt] << ' ' << g[rrt] << '\n';
        ans+=(lls!=llt?1:f[llt]+(lrt-llt))*(rrs!=rrt?1:g[rrt]+(rrt-rlt));
    }
    cout << ans << '\n';
    return ;
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin >> c >> t;
    if(c==13||c==14)flag=1;
    while(t--)solve();
    return 0;
}
/*
0 2
4 1
1 2 3 4
5 1
1 2 3 4 5
*/