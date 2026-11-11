#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll INF=0x3f3f3f3f3f3f3f3f;
int c,t,n;
ll d;
ll x[2000005];
ll dis[5005][5005];
ll ans=0;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        for(int i=1;i<=n;++i){
            cin>>x[i];
        }
        ans=0;
        if(c<=10){
            for(int i=1;i<n;++i){
                int l=i;
                for(int j=i+1;j<=n;++j){
                    if(l>n)dis[i][j]=INF;
                    else if(x[j]-x[l]<=d)dis[i][j]=dis[i][l]+1;
                    else{
                        l=j-1;
                        if(x[j]-x[l]<=d)dis[i][j]=dis[i][l]+1;
                        else l=n+1,dis[i][j]=INF;
                    }
                }
            }
            for(int i=1;i<n-1;++i){
                for(int j=i+2;j<=n;++j){
                    if(dis[i][j]==INF)break;
                    int cnt=0;
                    for(int k=i+1;k<j;++k){
                        if(dis[i][j]==dis[i][k]+dis[k][j])cnt++;
                    }
                    if(cnt==2)ans++;
                }
            }
            cout<<ans<<endl;
        }
        else if(c==11||c==12){
            ll dx=x[2]-x[1];
            ll len=d/dx*2;
            cout<<n-len+1<<endl;
        }
        else cout<<0<<endl;
    }
    return 0;
}