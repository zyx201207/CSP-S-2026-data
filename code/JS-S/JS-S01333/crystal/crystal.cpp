//JS-S01333
//remember to reset handin and debug
#include<bits/stdc++.h>
#define handin 1
#define debug 0
#define int long long
using namespace std;
constexpr int maxN=5e5+10;
int n,m,a[maxN],dp[maxN];
bool flag=true;
inline int f(){
    int ans=a[2]-a[1];
    for(int i=3;i<=n;i++){
        if(a[i]-a[i-1]!=ans)flag=false;
    }
    return ans;
}
signed main(){
    #if handin
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    #endif // handin
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    dp[0]=1;
    sort(a+1,a+1+n);
    int tmp=f(),t1=m;
    if(flag){
        int cnt=1,sum=0;
        for(;cnt<=n&&sum<t1;)
            {
                cnt++;
                sum+=tmp*cnt;
            }
        cout<<cnt;
        return 0;
    }
    int maxx=LLONG_MIN;
    int i=m;
    for(int j=1;j<=n;j++)
        if(a[j]-a[j-1]>=i){
            dp[j]=dp[j-1];
        }else{
            int t=i,cnt=1;
            for(int k=j-1;k>=1&&t>0;cnt++,k--)
                t-=(a[j]-a[k]);
            dp[j]=max(dp[j-1],cnt);
            maxx=max(dp[j],maxx);
        }
    cout<<maxx;
    return 0;
}
