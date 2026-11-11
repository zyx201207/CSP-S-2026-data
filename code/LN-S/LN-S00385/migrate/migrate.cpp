#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ri register int
using namespace std;
const int N=2e6+5;
ll c,T,n,d,a[N];
ll dis[1005][1005];

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>T;
    //spA
    if(c==11||c==12){
        while(T--){
            cin>>n>>d;
            for(ri i=1;i<=n;++i)cin>>a[i];
            ll g=d/(a[2]-a[1]);
            if(g==0||g==1||(n<=(2*g-1))){cout<<0<<'\n';continue;}
            cout<<n-(2*g-1)<<'\n';
        }
        return 0;
    }
        while(T--){
            cin>>n>>d;
            ll ans=0;
            for(ri i=1;i<=n;++i)cin>>a[i];
            memset(dis,0x3f3f3f3f,sizeof(dis));
            for(int i=1;i<=n-1;++i)
                for(int j=i+1;j<=n;++j)
                    if(a[j]<=a[i]+d)dis[i][j]=1;
                    else break;
            for(int i=1;i<=n;++i){
                for(int j=i+1;j<=n;++j){
                    if(a[j]<=a[i]+d)continue;
                    else{
                        int cnt=0;
                        for(int o=i+1;o<=j-1;++o){
                            if(dis[i][o]+dis[o][j]<dis[i][j]){
                                cnt=1;
                                dis[i][j]=dis[i][o]+dis[o][j];
                            }
                            else if(dis[i][o]+dis[o][j]==dis[i][j]){
                                ++cnt;
                            }
                        }
                        if(cnt==2)ans++;
                    }
                }
            }
            cout<<ans<<'\n';
        }
    
    return 0;
}