#include <iostream>
using namespace std;
int n,m;
int a[500005];
int b[500005];
int cnt[300005];
void c(int s)
{
	for(int i=s;i<n;i++)
	{
		cnt[a[i]]++;
		i=b[a[i]];
	}
	return;
}
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		b[a[i]]=i;
	}
	for(int i=0;i<n;i++)
	{
		c(i);
	}
	for(int i=1;i<=m;i++)
	{
		cout<<cnt[i]<<' ';
	}
	return 0;
}

