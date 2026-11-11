#include<bits/stdc++.h>
using namespace std;
#define int long long 
int n,len,step,t;
int line[500000],s[500000],ans[500000];
int a[500000],maxn=-1;
int dp[5000][5000];
signed main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
    cin>>n>>t;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
    	maxn=max(a[i],maxn);
	}
	cout<<maxn;
}
