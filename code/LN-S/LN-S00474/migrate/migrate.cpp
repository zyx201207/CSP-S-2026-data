#include<bits/stdc++.h>
using namespace std;
typedef long long i64;
#define rep(i,t1,t2,t3) for(decltype((t1)+(t2)+(t3)) i=(t1);i<=(t2);i+=(t3))
#define per(i,t1,t2,t3) for(decltype((t1)+(t2)+(t3)) i=(t1);i>=(t2);i-=(t3))
#define pb push_back
void work1(){
    //testcase 1~10 40pts
    i64 n,d;cin>>n>>d;
    vector<i64> x(n+1);
    rep(i,1,n,1) cin>>x[i];
    i64 ans=0;
    rep(i,1,n,1){
        vector<i64> dp(n+1),dis(n+1),cnt(n+1);
        dis[i]=0,dp[i]=1,cnt[0]=1;
        i64 P=i;
        deque<i64> q;q.pb(i);
        rep(j,i+1,n,1){
            while(P<j && x[j]-x[P]>d){
                if(q.front()==P) q.pop_front();
                cnt[dis[P]]-=dp[P],P++;
            }
            if(!q.empty()){
                i64 mnval=dis[q.front()];
                dis[j]=mnval+1,dp[j]=cnt[mnval],ans+=(dp[j]==2);
            }else break;
            //cout<<i<<' '<<j<<':'<<dp[j]<<'\n';
            //if(dp[j]==2) cout<<i<<' '<<j<<'\n';
            while(!q.empty() && dis[q.back()]>=dis[j]) q.pop_back();
            q.pb(j),cnt[dis[j]]+=dp[j];
        }
    }
    cout<<ans<<'\n';

}
void work2(){
    //testcase 11,12 8pts
    i64 n,d;cin>>n>>d;
    vector<i64> x(n+1);
    rep(i,1,n,1) cin>>x[i];
    i64 ans=0;
    vector<i64> dp(n+1),dis(n+1),cnt(n+1);
    dis[1]=0,dp[1]=1,cnt[0]=1;
    i64 P=1;
    deque<i64> q;q.pb(1);
    rep(j,2,n,1){
        while(P<j && x[j]-x[P]>d){
            if(q.front()==P) q.pop_front();
            cnt[dis[P]]-=dp[P],P++;
        }
        if(!q.empty()){
            i64 mnval=dis[q.front()];
            dis[j]=mnval+1,dp[j]=cnt[mnval],ans+=(dp[j]==2)*(n-j+1);
        }else break;
        while(!q.empty() && dis[q.back()]>=dis[j]) q.pop_back();
        q.pb(j),cnt[dis[j]]+=dp[j];
    }
    cout<<ans<<'\n';
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    i64 c,t;cin>>c>>t;
    while(t--){
        if(c<=10) work1();
        else work2();
    }
    return 0;
}
