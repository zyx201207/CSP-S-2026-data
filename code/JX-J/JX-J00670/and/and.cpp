#include<bits/stdc++.h>
using namespace std;
long long a[200005],dp[200005];
string s[200005];
int main(){
    //freopen("and.in","r",stdin);
    //freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    dp[0]=pow(2,31);
    sort(a,a+n+1);
    for(int i=m;i<=n;i++){
        for(int j=i-m;j<i;j++){
            dp[i]=max(dp[i],dp[i]&a[j]);
        }
    }
    cout<<a[n-m+1];
}
