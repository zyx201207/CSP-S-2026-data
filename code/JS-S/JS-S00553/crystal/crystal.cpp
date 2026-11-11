#include<bits/stdc++.h>
using namespace std;
long long n,m,l;
long long a[500010],sum[500010];
long long mx=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
		sum[i]=sum[i-1]+a[i];
	for(int r=1;r<=n;r++){
		while(l<r&&a[r]*(r-l+1)-(sum[r]-sum[l-1])>m)
			l++;
		mx=max(mx,r-l+1);
	}
	cout<<mx;
	return 0;
}