#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200010];
int dp[200010][200010];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    int mx=0x3f3f3f3f;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        mx=min(a[i],mx);
    }
    cout<<mx;
    return 0;
}
