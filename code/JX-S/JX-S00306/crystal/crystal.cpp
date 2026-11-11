#include<bits/stdc++.h>
using namespace std;
int a[500005];
int dp[500005];
int q[500005];
long long n,m;
void dfs(int n1){

    if(a[n1]-a[n1-1]<=m){
        if(m-q[n1-1]>=a[n1]-a[n1-1]&&m-q[n1-1]>=0){

            long long x=(a[n1]-a[n1-1])*dp[n1-1];
            if(x+q[n1-1]>m){
                dp[n1]=int(((m-q[n-1])/(a[n1]-a[n1-1]))+0.5);
                q[n1]=q[n1-1]+(dp[n1]-1)*(a[n1]-a[n1-1]);
            }
            else{
                dp[n1]=dp[n1-1]+1;
                q[n1]=q[n1-1]+(a[n1]-a[n1-1]);
            }
        }
        else{
            int count=0;
            int m1=m;
            int a1=a[n1];
            for(int i=n1;i>0;i--){
                if(a1-a[i-1]<=m1){
                    m1-=(a[i]-a[i-1]);
                    count++;
                }
                else{
                    break;
                }
            }
            dp[n1]=count+1;
            q[n1]=m-m1;
        }
    }
    else{
        dp[n1]=1;
    }
/*
    int count=0;
    int m1=m;
    int a1=a[n1];
    for(int i=n1;i>0;i--){
        if(a1-a[i-1]<=m1&&m1>0){
            m1-=(a1-a[i-1]);
            a1-=a[i-1];
            count++;
        }
        else{
            break;
        }
    }
    dp[n1]=count;
    //q[n1]=m-m1;*/
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    memset(q,0,sizeof(q));
    memset(dp,0,sizeof(dp));
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    dp[1]=1;
    for(int i=2;i<=n;i++){
        dfs(i);
      //  cout<<dp[i]<<' ';
    }
    int maxx=0;
    for(int i=1;i<=n;i++){
        maxx=max(maxx,dp[i]);
    }
    cout<<maxx;
    return 0;
}
