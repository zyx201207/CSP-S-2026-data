#include<bits/stdc++.h>
using namespace std;
long long int n,m,a[200005],ans,b[200005],t=0;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	cin>>a[i];
	sort(a+1,a+1+n,greater<long long int>());
	ans=a[1];
	for(int i=2;i<=m;i++)
	{
		ans=(ans&a[i]);
	}
	cout<<ans;
	return 0;
}