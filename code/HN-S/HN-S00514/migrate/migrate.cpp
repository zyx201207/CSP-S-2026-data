#include<bits/stdc++.h>
using namespace std;
#define int long long
#define rint register int
#define INF 1000000000

int c,n,d,a[2000005],pos[2000005],f[2000005],g[2000005];
inline void solve(){
    cin>>n>>d;
    for(rint i=1;i<=n;i++){
        cin>>a[i];
        pos[i]=pos[i-1];
        while(a[i]-a[pos[i]]>d)pos[i]++;
    }
    if(c>13){
        cout<<"0\n";
        return ;
    }
    rint res=0;
    for(rint i=1;i<=n;i++){
        f[i]=0,g[i]=1;
        for(rint j=i+1;j<=n;j++){
            f[j]=INF,g[j]=0;
            rint k=max(i,pos[j]);
            if(k<j){
                if(f[j]>f[k]+1)f[j]=f[k]+1,g[j]=g[k];
                else if(f[j]==f[k]+1)g[j]+=g[k];
            }
            k++;
            if(k<j){
                if(f[j]>f[k]+1)f[j]=f[k]+1,g[j]=g[k];
                else if(f[j]==f[k]+1)g[j]+=g[k];
            }
            k++;
            if(k<j){
                if(f[j]>f[k]+1)f[j]=f[k]+1,g[j]=g[k];
                else if(f[j]==f[k]+1)g[j]+=g[k];
            }
            if(g[j]==2)res++;
        }
    }
    cout<<res<<"\n";
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    rint t;cin>>c>>t;
    if(11<=c&&c<=12){
        while(t--){
            cin>>n>>d;
            for(rint i=1;i<=n;i++)cin>>a[i];
            if(n==1){
                cout<<"0\n";
                continue;
            }
            rint t=a[2]-a[1];
            if(d<2*t)cout<<"0\n";
            else cout<<max(0ll,n-d/t*2+1)<<"\n";
        }
        return 0;
    }
    pos[0]=1;
    while(t--)solve();
    return 0;
}