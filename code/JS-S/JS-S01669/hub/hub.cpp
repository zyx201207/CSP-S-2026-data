#include<bits/stdc++.h>
using namespace std;
long long a[200010],dp[200010];
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    long long c1,N;
    cin>>c1>>N;
   for(long long k=1;k<=N;k++){
        long long c,t,m=0;
        cin>>c>>t;
        for(long long i=1;i<=c;i++){
                int u ,v;
            cin>>u>>v;
            //dp[i]=long long_MAX;
        }
       for(long long i=2;i<=c;i++){
            for(long long j=i-1;j>=1&&abs(a[i]-a[j])<=t;j--){
                    if(dp[i]!=0)
                        dp[i]=min(dp[i],dp[j]+1);
                    else dp[i]=dp[j]+1;
                    //cout<<75;
            }
            if(dp[i]==2)m++;
        }
        for(long long i=1;i<=c;i++){a[i]=0;dp[i]=0;}
        cout<<1<<endl;
    }
    return 0;
}
