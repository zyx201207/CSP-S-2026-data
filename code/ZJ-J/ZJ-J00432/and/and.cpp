#include <bits/stdc++.h>
using namespace std;
int n,m;
long long a[200005],sum;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i)cin>>a[i];
	sort(a+1,a+n+1);
	sum=a[n];
	for(int i=2;i<=m;++i)
	{
		sum=sum&a[n-i+1];
	}
	cout<<sum;
	return 0;
	fclose(stdin);
	fclose(stdout);	
}
