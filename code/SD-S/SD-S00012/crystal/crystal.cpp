#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500010],sum[500010];
main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	int l=1;
	while(l<=n&&a[n]*(n-l)-sum[n]-sum[l-1]>m){
		l++;
	}
	cout<<l;
}
