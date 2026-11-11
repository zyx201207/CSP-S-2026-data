#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int c,n,m,d,q,w[50010],k[510],a[510][50010],t[510][50010],ans;
int x[10010],y[10010],s,si,g,gi;
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i =1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for (int j=1;j<=2*k[i];j+=2) 
		{
			cin >> a[i][j];
			cin >> t[i][j];
		}
	}
	for (int i = 1;i<=q;i++)
	{
		cin >> x[i];
		cin >> y[i];
	}
	for(int f = 1;f<=q;f++)
	{
		ans=0;
		for (int i =1;i<=n;i++)
		{
			for(int j =1;j<=k[i];j++)
			{
				if (x[q] = a[i][j])
				{
					s = i;
					g = j;
					break;
				}
			 } 
		}
		ans = ans +w[x[q]]+t[s][g];
		for (int i =1;i<=n;i++)
		{
			for(int j =1;j<=k[i];j++)
			{
				if (a[s][g+1] = y[q])
				{
					s = i;
					g = j;
					break;
				}
				if (a[s][g+1] = a[i][j])
				{
					s = i;
					g = j;
					ans +=t[i][j];
				}
			 } 
		}
		ans = ans +w[y[q]]+t[s][g];
		cout <<ans<<endl;
	}
	return 0;
}
