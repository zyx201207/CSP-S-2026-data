#include<bits/stdc++.h>
#define long long int
using namespace std;
int a[114514*2];
int dp[114514*2];
int main() {
ios::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);

freopen("and.in","r",stdin);
freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++) {
        cin>>a[i];
    }
    dp[1]=a[1] & a[2];
    for(int i=2;i<=n;i++) {
        for(int j=i;j<=n;j++) {
                int c=a[j] & a[i];
            dp[j]=max(dp[j],c);
        }
    }
    cout<<dp[n];
    return 0;
}
//password:Trick||Treat!
