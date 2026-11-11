#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[202020],dp[202020],c[202020];
int main() {
    freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++){
    	cin>>a[i];
    	dp[i]=a[i];
    	c[i]=1;
	}
    sort(a+1,a+n+1);
    for(int i=n;i>=n-m-6;i--)
    cout<<a[i]<<' ';
    cout<<a[n+1-m];
	return 0;
}

