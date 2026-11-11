#include<bits/stdc++.h>
using namespace std;
int a[200010],dp[200010];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int cnt=0;
    for(int i=1;i<=n;i++)cin>>a[i];
    int sum=0;
    sum=a[1];
    for(int i=2;i<=n;i++){
        sum=(sum&a[i]);
    }
    cout<<sum;
    return 0;
}
