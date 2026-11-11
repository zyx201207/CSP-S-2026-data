#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
int dp[500005];
int sum=0;

int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        dp[i]=a[i];
        for(int j=1;j<=i;j++){

            if(dp[i]>=dp[j]){
                dp[i]+=dp[i]-dp[j];
                sum++;
                if(sum>=m){
                    cout<<i<<endl;
                    return 0;
                }
            }
        }
    }

    return 0;
}
