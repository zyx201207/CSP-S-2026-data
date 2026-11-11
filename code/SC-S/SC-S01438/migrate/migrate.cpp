#include<bits/stdc++.h>
using namespace std;
long long dp[5010];
long long t,n,d;
long long pos[5010];
long long ways[5010];
long long lst[5010];
long long sum[5010];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
    {
        int c;
        cin>>c;
    }
    cin>>t;
    while(t--){
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>pos[i];
        }
        int x=1;
        for(int i=1;i<=n;i++){
            while(pos[i]-pos[x]>d)x++;
            lst[i]=x;
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                dp[j]=0x3f3f3f3f;
                ways[j]=0;
                sum[j]=0;
            }
            sum[i]=1;
            ways[i]=1;
            dp[i]=0;
            int maxx=1,maxi=i;
            for(int j=i+1;j<=n;j++){
                if(lst[j]==j)break;
                dp[j]=dp[max(i*1ll,lst[j])]+1;
                if(dp[j]>maxx){
                    maxi=j-1;
                    maxx=dp[j];
                }
                ways[j]=min(sum[maxi]-sum[max(i*1ll,lst[j])-1],3ll);
                sum[j]=sum[j-1]+ways[j];
                ans+=(ways[j]==2);
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}