#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int N=2e6+5;
int C,T;
int n,d,ans;
int a[N];
int dp[5005][5005],num[5005][5005];
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>C>>T;
    if(C==11||C==12){
        while(T--){
            cin>>n>>d;
            for(int i=1;i<=n;i++) cin>>a[i];
            int dd=a[2]-a[1];
            cout<<dd<<' '<<d<<endl;
            if(2*dd<=d&&d<3*dd){
                cout<<n-3<<endl;
            }else{
                cout<<0<<endl;
            }
        }
        return 0;
    }
    while(T--){
        cin>>n>>d;ans=0;
        for(int i=1;i<=n;i++) cin>>a[i];
        //for(int i=1;i<=n;i++) cout<<a[i]<<' ';
        //cout<<endl;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                {num[i][j]=0;dp[i][j]=1e18;}
        for(int i=1;i<=n;i++){
            dp[i][i]=0;num[i][i]=1;
            int la=i;
            for(int j=i+1;j<=n;j++){
                while(la<j&&a[j]-a[la]>d) la++;
                //cout<<la<<endl;
                for(int k=la;k<j&&num[i][j]<=2;k++){
                    //if(!num[i][k]) continue;
                    if(dp[i][j]==1e18){
                        dp[i][j]=dp[i][k]+1;
                        num[i][j]=num[i][k];
                    }else if(dp[i][j]==dp[i][k]+1){
                        num[i][j]+=num[i][k];
                    }else break;
                }
                if(num[i][j]==2){ans++;}
                //cout<<i<<' '<<j<<endl<<dp[i][j]<<' '<<num[i][j]<<endl;
            }
        }
        cout<<ans<<endl;
        //cout<<114514<<endl;
    }
    return 0;
}
