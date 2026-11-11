#include<iostream>
#include<cstdio>
#include<cmath>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=2*1e5+7;
long long dp[N];
int a[N];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        for(int j=m;j>=1;j--){
            dp[j]=max(1LL*a[i],dp[j-1]&a[i]);
        }
    }
    cout<<dp[m];
    return 0;
}
