#include<bits/stdc++.h>
using namespace std;
const int N=2*1e5+5;
int n,m,a[N];
long long dp[N][N];
int cc(int x,int y){
return x^y;
}
int main(){
//freopen("and.in","r",stdin);
 cin>>n>>m;
 for(int i=1;i<=n;i++){
    cin>>a[i];
 }

 for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++){
        if(dp[i-1][j]<a[i]&a[i-1])dp[i][j]=cc(a[i],a[i-1]);
    }


cout<<dp[n][m];
//freopen("and.out","w",stdout);
 return 0;
}
