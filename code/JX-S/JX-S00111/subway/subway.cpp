#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,p;
int a[500050],w[500050],k[500050],dp[500050];
int main(){
    freopen("subway.in","r,stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>c>>n>>m>>d>>p;
    for(int i=1;i<=a[m];i++){
        cin>>w[i];
    }
    for(int i=1;i<=m;i++){
        dp[i]=min(dp[i],w[i-1]+k[i]);
    }
    cout<<dp[m]<<endl;
    return 0;
}
