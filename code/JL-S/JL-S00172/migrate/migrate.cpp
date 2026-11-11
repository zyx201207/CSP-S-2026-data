#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,d;
int x[2000005];
namespace solve1{//1~10 
int dis[5005],dp[5005];
int sum[5005];
void solve(){
    int ans =0;
    for(int i = 1; i <= n; i++){
        memset(sum,0,sizeof sum);
        queue<int>q;
        dis[i]=0,dp[i]=1;
        sum[0]=1;
        q.push(i);
        for(int j = i+1; j <= n; j++){
            while(q.size()&&x[j]-x[q.front()]>d){
                sum[dis[q.front()]]-=dp[q.front()];
                q.pop();
            }
            dis[j]=dis[q.front()]+1;
            dp[j]=min(sum[dis[j]-1],3ll);
            sum[dis[j]]+=dp[j];
            q.push(j);
            if(dp[j]==2)ans++;
        }
    }
    cout << ans<<'\n';
}
}
namespace solve2{//11,12
void solve(){
    int a = x[2]-x[1];
    d=d/a;
    int ans = 0;
    for(int i = 1; i <= n; i++){
        int l = i+d+1,r=i+d*2-1;
        l=max(l,1ll),r=min(r,n);
        r=max(r,0ll),l=min(l,n+1);
        if(i+d*2-1<=r&&i+d*2-1>=l)ans++;
        // cout << l <<' '<<r<<'\n';
    }
    cout << ans<<'\n';
}
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int C,T;
    cin >> C >> T;
    while(T--){
        cin >> n >> d;
        for(int i = 1; i <= n; i++)cin >> x[i];
        if(n==1)cout << 0 << '\n';
        else if(C<=10)solve1::solve();
        else if(C<=12)solve2::solve();
    }
    return 0;
}