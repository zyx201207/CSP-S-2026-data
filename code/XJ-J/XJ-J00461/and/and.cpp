#include<bits/stdc++.h>
using namespace std;
long long a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m,i,ans;
	cin>>n>>m;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	ans=a[n];
	for(i=n-1;i>=n-m+1;i--)
	{
		ans=ans&a[i];
	}
	cout<<ans;
	return 0;
}
