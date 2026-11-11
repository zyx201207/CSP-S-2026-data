#include<bits/stdc++.h>
#include<bits/extc++.h>
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
#define db(x) cout<<#x<<" "<<x<<endl;
using namespace __gnu_cxx;
using namespace std;
const int inf=0x3f3f3f3f3f3f3f3f;
int c,t,n,D,a[2000010],d[5010][5010],cnt[5010][5010];
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>D;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        if(n<=5000){
            int ans=0;
            for(int i=1;i<=n;i++) d[i][i]=cnt[i][i]=1;
            for(int len=1;len<=n;len++){
                for(int l=1;l<=n-len+1;l++){
                    int r=l+len-1;
                    d[l][r]=(((a[r]-a[l])<=D)?1:inf);
                    for(int i=l+1;(i<r&&i<=n&&a[i]-a[l]<=D);i++){
                        d[l][r]=min(d[l][r],d[i][r]+1);
                    }
                }
            }
            for(int len=1;len<=n;len++){
                for(int l=1;l<=n-len+1;l++){
                    int r=l+len-1;
                    if(d[l][r]==1){
                        cnt[l][r]=1;continue;
                    }
                    cnt[l][r]=0;
                    for(int i=l+1;(i<r&&i<=n&&a[i]-a[l]<=D);i++){
                        if(d[l][r]==d[i][r]+1){
                            cnt[l][r]+=cnt[i][r];
                        }
                    }
                    if(cnt[l][r]==2) ans++;
                }
            }
            cout<<ans<<"\n";
        }
        else if(c==11||c==12){
            int dd=a[2]-a[1],ans=0;
            if(2*dd>D){
                cout<<0<<endl;
                continue;
            }
            for(int i=1;i<=n;i++){
                ans+=min(dd-1,n-i-dd);
            }
            cout<<ans<<"\n";
        }
    }
    return 0;
}
