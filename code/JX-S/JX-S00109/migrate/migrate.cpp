#include<bits/stdc++.h>
#define ll long long
using namespace std;
int C,T;
int n;
ll d;
ll x[2000005];
map<int,ll> f[2000005];
int main(){
    //freopen("migrate.in","r",stdin);
    //freopen("migrate.out","w",stdout);
    cin>>C>>T;
    while(T--){
        //f.swap({});
        cin>>n>>d;
        cin>>x[1];
        bool ss=0;
        for (int i=2;i<=n;i++){
            cin>>x[i];
            if (x[i]-x[i-1]>d)ss=1;
        }
        if (ss || n==1){cout<<0<<"\n";continue;}
        ll ans=0ll;
        for (int i=1;i<=n;i++){
            for (int j=i+2;j<=n;j++){
                int cnt=0;
                int xx=i;
                int xy=2;
                while(1){
                    while(xy<=j && x[xy]-x[xx]<=d){
                        xy++;
                    }
                    xy--;
                    xx=xy;
                    xy++;
                    cnt++;
                    if (xx==j)break;
                }

                f[i][0]=1;
                for (int sa=i;sa<=j;sa++){
                    for (auto[tt,kk]:f[sa]){
                        for (int ii=sa+1;ii<=j;ii++){
                            if (x[ii]-x[tt]>d)break;
                            f[ii][tt+1]+=kk;
                        }

                    }
                }
                if (f[i][cnt]==2)ans++;
            }
        }
        cout<<ans<<"\n";
    }

}
