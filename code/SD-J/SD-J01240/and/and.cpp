#include<bits/stdc++.h>
using namespace std;
int a[200900],n,m;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	int ans=a[n];
	for(int i=n-m+1;i<=n;i++)
	{
		ans=ans&a[i];
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
 } 
