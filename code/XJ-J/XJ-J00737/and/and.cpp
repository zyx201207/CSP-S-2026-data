#include<bits/stdc++.h>
using namespace std;
long long int n,m,a[900005],i,ans;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n;i++)
	cin>>a[i];
	sort(a+1,a+1+n,greater<long long int>());
	ans=a[1];
	for(i=2;i<=m;i++)
	ans=ans&a[i];
	if(ans==0)
	{
		cout<<a[2];
		return 0;
	}
	cout<<ans;
	return 0;
}