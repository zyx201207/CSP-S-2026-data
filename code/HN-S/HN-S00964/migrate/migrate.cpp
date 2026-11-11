#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+10,M=5e3+10;
int C,T,n,d,ans,x[N],a[N];//dp[i][j]表示 i->j的方案数
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>C>>T;
    while(T--){
        ans=0;
        cin>>n>>d;
        for(int i=1;i<=n;i++)  
            cin>>a[i];
        if(C>10&&C<=12){
            int gap=a[2]-a[1];
            // cout<<gap<<' '<<d<<' '<<n<<'\n';
            if(gap*2<=d){    
                for(int i=1;i<=n;i++){
                    int res=n-i;
                    res-=d/gap-1;
                    ans+=min(1ll,res/(d/gap));
                }
            }
            cout<<ans<<'\n';
        }
        else{
            for(int i=1;i<=n;i++){
                int pre=i,cnt=0,end=0;
                while(end!=n){
                    // cout<<pre<<' '<<cnt<<'\n';
                    while(end<n&&a[end+1]-a[pre]<=d){
                        end++;
                        if(cnt==0&&pre>i){
                            if(a[end]-a[pre-1]<=d&&(a[end]-a[pre-2]>d||pre==i+1)){
                                ans++;
                                // cout<<-1<<' '<<i<<' '<<pre<<' '<<end<<'\n';
                            }
                        }
                        else if(cnt==1&&pre>i){
                            if(a[end]-a[pre-1]>d){
                                // cout<<i<<' '<<end<<'\n';
                                ans++;
                            }
                        }
                        else if(cnt>1)
                            break;
                    }
                    if(cnt>1)
                        break;
                    if(pre!=i){
                        if(a[end]-a[pre-1]<=d)
                            cnt++;
                        if(pre!=i+1&&a[end]-a[pre-2]<=d)  
                            cnt++;
                    }
                    if(pre==end)
                        break;
                    pre=end;
                }
            }
            cout<<ans<<'\n';
        }
    }
    return 0;
}   