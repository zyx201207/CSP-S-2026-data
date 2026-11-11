#include<bits/stdc++.h>
using namespace std;
int main()
{
//	freopen("card.in","r",stdin);
//	freopen("card.out","w",stdout);
long long n,m,a[500010],b[300010];
cin>>n>>m;
for(int i=1;i<=n;i++)
{
	cin>>a[i];
}
for(int i=1;i<=m;i++)
{
	b[i]=n;
}
for(int i=1;i<=n;i++)
{
	for(int j=i;j<=n;j++)
	{
		if(a[j]==a[j+1])
		{
			b[a[j]]--;
		}
	}
}
for(int i=1;i<=m;i++)
{
	cout<<b[i]<<" ";
}
		return 0;
}
