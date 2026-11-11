#include <bits/stdc++.h>
using namespace std;
#define int long long
const int nn=2e6+5;
int cs,tes,n,d,f[nn],x[nn],t[nn],mn[nn];

signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>cs>>tes;
    //cout<<cs<<'\n';
    while(tes--){
        cin>>n>>d;
        for(int i=1;i<=n;i++)cin>>x[i];
        for(int i=1,j=1;i<=n;i++){
            while(j+1<=n && x[j+1]-x[i]<=d)j++;
            t[i]=j;
        }
        int ans=0;
        if(cs==11 || cs==12 || cs==0){
            int ts=t[1]-1;
            if(ts==0 || ts==1){
                cout<<0<<'\n';
                continue;
            }
            for(int i=1;i<=n;i++){
                int vs=(n-i),ds=0;
                if(vs>ts)ds=min(vs-ts,ts-1);
                if(ds>=ts-2)ds-=(ts-3);
                else ds=0;
                ans+=ds;
            }
            cout<<ans<<'\n';
            continue;
        }
        if(0<=cs && cs<=6){
            for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++)f[j]=0,mn[j]=1e18;
                mn[i]=0,f[i]=1;
                for(int j=i;j<=n;j++){
                    for(int k=j+1;k<=t[j];k++){
                        if(mn[k]>mn[j]+1)mn[k]=mn[j]+1,f[k]=f[j];
                        else if(mn[j]+1==mn[k])f[k]+=f[j];
                    }
                }
                for(int j=i;j<=n;j++){
                    if(f[j]==2)ans++;
                }
            }
            cout<<ans<<'\n';
            continue;
        }

    }
    return 0;
}
