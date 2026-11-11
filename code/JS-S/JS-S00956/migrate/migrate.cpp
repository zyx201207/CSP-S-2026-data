#include<bits/stdc++.h>
using namespace std;
long long dp[5005][5005],a[2000005];
__int128 cnt[5005][5005];
long long fdp[2000005],fsum[2000005];
unordered_map<long long,__int128> ma;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long long c,t;
    cin>>c>>t;
    if(c == 11 || c == 12){
        while(t--){
            long long n,d;
            cin>>n>>d;
            if(n == 1){
                cout<<"0\n";
                continue;
            }
            for(long long i = 1;i<=n;i++){
                cin>>a[i];
            }
            long long di = a[2]-a[1];
            d/=di;
            for(long long i = 1;i<=d;i++){
                fdp[i] = 1;
                fsum[i] = i;
            }
            for(long long i = d+1;i<=n;i++){
                fdp[i] = 0;
                fdp[i]+=(fsum[i-1]-fsum[max(0ll,i-d-1)]);
                fsum[i] = fsum[i-1]+fdp[i];
                if(fdp[i]>2) break;
            }
            long long ans = 0;
            for(long long i = 1;i<=n;i++){
                if(fdp[i] == 2){
                    ans+=(n-i);
                }
            }
            cout<<ans<<'\n';
        }
        return 0;
    }
    while(t--){
        long long n,d;
        cin>>n>>d;
        for(long long i = 1;i<=n;i++) cin>>a[i];
        for(long long i = 1;i<=n;i++){
            for(long long j = 1;j<=n;j++){
                dp[i][j] = 1e18;
                cnt[i][j] = 0;
            }
        }
        for(long long i = 1;i<=n;i++){
            dp[i][i] = 0;
        }
        for(long long i = 1;i<=n;i++){
            ma.clear();
            deque<long long> dq;
            dq.push_back(i);
            ma[0] = 1;
            for(long long j = i+1;j<=n;j++){
                long long minn = 1e18;
                while(!dq.empty() && abs(a[j]-a[dq.front()])>d){
                    ma[dp[i][dq.front()]]-=cnt[i][dq.front()];
                    dq.pop_front();
                }
                if(!dq.empty()){
                    dp[i][j] = dp[i][dq.front()]+1;
                    cnt[i][j] = ma[dp[i][dq.front()]];
                }
                while(!dq.empty() && dp[i][dq.back()]>dp[i][j]){
                    ma[dp[i][dq.back()]]-=cnt[i][dq.back()];
                    dq.pop_back();
                }
                dq.push_back(j);
                ma[dp[i][j]]+=cnt[i][j];
            }
        }
        long long ans = 0;
        for(long long i = 1;i<=n;i++){
            for(long long j = i+1;j<=n;j++){
                ans+=(cnt[i][j] == 2);
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}
