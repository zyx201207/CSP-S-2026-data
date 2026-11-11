#include<bits/stdc++.h>
using namespace std;
const int N=500010;
int n;
long long m;
long long a[N];
pair<long long,int> dp[N][2];
queue<int> nxt1,nxt2;
long long num1,num2;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%d%lld",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    sort(a+1,a+n+1);
    int t=a[2]-a[1];
    for(int i=3;i<=n;i++){
        if(a[i]-a[i-1]!=t){
            t=-1;
            break;
        }
    }
    if(t!=-1){
        int ans=1;
        for(int i=1;i<=n;i++){
            ans++;
            m-=i*t;
            if(m<0){
                ans--;
                break;
            }
        }
        printf("%d",ans);
        return 0;
    }
    dp[1][0].first=0;
    dp[1][0].second=0;
    dp[1][1].first=0;
    dp[1][1].second=1;
    nxt2.push(1);
    num2=a[1];
    for(int i=2;i<=n;i++){
        long long p1=dp[i-1][0].first;
        long long p2=dp[i-1][1].first;
        int q1=dp[i-1][0].second;
        int q2=dp[i-1][1].second;
        if(q1<q2){
            dp[i][0].first=p2;
            dp[i][0].second=q2;
            num1=num2;
            nxt1=nxt2;
            nxt2.push(i);
            dp[i][1].first=p2+1LL*q2*(a[i]-num2);
            num2=a[i];
            dp[i][1].second=q2+1;
            while(dp[i][1].first>m){
                dp[i][1].first-=(a[i]-a[nxt2.front()]);
                dp[i][1].second-=1;
                nxt2.pop();
            }
        }
        else if(q1>q2){
            dp[i][0].first=p1;
            dp[i][0].second=q1;
            num2=num1;
            nxt2=nxt1;
            nxt2.push(i);
            dp[i][1].first=p1+1LL*q1*(a[i]-num1);
            num2=a[i];
            dp[i][1].second=q1+1;
            while(dp[i][1].first>m){
                dp[i][1].first-=(a[i]-a[nxt2.front()]);
                dp[i][1].second-=1;
                nxt2.pop();
            }
        }
        else{
            if(p1<p2){
                dp[i][0].first=p1;
                dp[i][0].second=q1;
                num2=num1;
                nxt2=nxt1;
                nxt2.push(i);
                dp[i][1].first=p1+1LL*q1*(a[i]-num1);
                num2=a[i];
                dp[i][1].second=q1+1;
                while(dp[i][1].first>m){
                    dp[i][1].first-=(a[i]-a[nxt2.front()]);
                    dp[i][1].second-=1;
                    nxt2.pop();
                }
            }
            else if(p1>p2){
                dp[i][0].first=p2;
                dp[i][0].second=q2;
                num1=num2;
                nxt1=nxt2;
                nxt2.push(i);
                dp[i][1].first=p2+1LL*q2*(a[i]-num2);
                num2=a[i];
                dp[i][2].second=q2+1;
                while(dp[i][1].first>m){
                    dp[i][1].first-=(a[i]-a[nxt2.front()]);
                    dp[i][1].second-=1;
                    nxt2.pop();
                }
            }
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        ans=max({ans,dp[i][0].second,dp[i][1].second});
    }
    printf("%d",ans);
    return 0;
}
