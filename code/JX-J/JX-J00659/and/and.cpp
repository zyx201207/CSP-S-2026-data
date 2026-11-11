#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m;
long long a[N];
long long dp[N];
long long maxn=-1;
long long sum;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","W",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        maxn=max(maxn,a[i]);
    }
    if(n==m){
        sum=a[1];
        for(int i=1;i<=n;i++){
            sum&=a[i];
        }
        cout<<sum;
        return 0;
    }
    dp[0]=maxn;
    for(int i=1;i<=n;i++){
        for(int j=m;j>=1;j--){
            dp[j]=max(dp[j],dp[j-1]&a[i]);
        }
    }
    cout<<dp[m];
    return 0;
}
