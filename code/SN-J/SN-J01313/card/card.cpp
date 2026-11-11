#include<bits/stdc++.h>
using namespace std;
long long a[500005],n,m,z[500005],c[300005],id,cnt,b[500005],shu[500005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	a[0] = -1;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
	} 
	
	for(int i = 1;i <= n;i++)
	{
		for(int j = 1;j <= m;j++)
		{
			c[j] = 0;	
		} 
		for(int j = i;j <= n;j++)
		{
			c[a[j]] = 1;
		} 
		for(int j = 1;j <= m;j++)
		{
			if(c[j] == 1)
				z[j]++;
		} 
	}
	for(int i = 1;i <= m;i++)
	{
		cout << z[i] << " ";
	}
	return 0;
}
