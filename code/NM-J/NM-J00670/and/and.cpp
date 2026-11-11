#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],maxx;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n,greater<int>() );
	maxx=a[1];
	for(int i=2;i<=m;i++)
	{
		maxx=maxx&a[i];
	}
	cout<<maxx;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
