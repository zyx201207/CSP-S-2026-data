#include<iostream>
#include<cstring>
using namespace std;
long long ans[400005];
long long a[500006];
long long vis[5000006];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for (int i=1;i<=n-1;i++)
	{
		cout<<0<<" ";
	}
	cout<<n;
	return 0;
}