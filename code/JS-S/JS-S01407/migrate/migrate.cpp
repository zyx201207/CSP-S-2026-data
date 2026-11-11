#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL c,t;
LL n,d;
LL x[2000005];
LL cnt;
void solve(){
    cin>>n>>d;
    for(int i=1;i<=n;i++){
        cin>>x[i];
    }
    cnt=0;
    LL ans=0;
    for(int i=1;i<=n;i++){
        for(int j=i+2;j<=n;j++){
            cnt=0;
            for(int u=i+1;u<j;u++){

                if(x[u]-x[i]<=d&&x[j]-x[u]<=d){
                    cnt++;
                    //cout<<i<<' '<<j<<' '<<u<<'\n';
                }

            }
            if(cnt>=2)
                    ans++;
        }

    }
    cout<<ans<<'\n';
}
int  main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin.tie(nullptr)->sync_with_stdio(0);
    cin>>c>>t;


        for(int i=1;i<=t;i++)
            solve();


}

