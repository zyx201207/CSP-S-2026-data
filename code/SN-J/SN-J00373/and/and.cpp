#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[100005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	long long maxx=INT_MIN;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n-m+1;i++)
	{
		long long p=a[i];
		for(int j=1;j<=m;j++){
			p=p&a[i+j];
		}
		maxx=max(p,maxx);
	}
	cout<<maxx;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
