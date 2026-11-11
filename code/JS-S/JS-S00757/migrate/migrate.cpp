#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int c,T;
int n;ll d;
ll a[2000007];
int l[2000007],r[2000007];
int dp[2000007];
int cnt[2000007];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>T;
    while(T--){
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        int ans=0;
        //cout<<"\n ans::";
        for(int i=1;i<=n;i++){
            ll low=a[i]-d,high=a[i]+d;
            if(a[i]>0&&2e18-a[i]<d)high=1e18+1;
            r[i]=upper_bound(a+1,a+n+1,high)-a-1;
            //cout<<r[i]<<" ";
        }
        //cout<<r[8]<<"\n";
        //cout<<"\n";
        for(int u=1;u<=n;u++){
            for(int i=1;i<=n;i++)cnt[i]=0,dp[i]=2e9;
            dp[u]=0,cnt[u]=1;
            for(int t=u;t<=n;t++){
                for(int k=t+1;k<=r[t];k++){
                    int now=dp[t]+1;
                    if(now<=dp[k]){
                        if(now<dp[k])cnt[k]=cnt[t],dp[k]=now;
                        else{
                            //if(k==9&&t==8)cout<<cnt[k]<<" "<<cnt[t]<<"\n";
                            cnt[k]+=cnt[t];
                        }
                    }
                }
            }
            //if(u==1)cout<<cnt[8]<<" "<<cnt[9]<<" "<<dp[9]<<"\n";
            for(int v=u+1;v<=n;v++){
                if(cnt[v]==2)ans++;
            }
        }
        cout<<ans<<"\n";
        if(c==13||c==14){

        }
    }
    return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 1
10 3
0 3 6 7 8 9 10 11 14 17
-1000000000000000000 -999999999999999997 -999999999999999994 -999999999999999993 -999999999999999992 -999999999999999991 -999999999999999990 -999999999999999989 -999999999999999986 -999999999999999983
*/
