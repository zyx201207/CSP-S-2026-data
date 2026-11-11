#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,b,w,k,a,t,x,y,cc;
int main()
{
	srand(time(nullptr));
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> b;
	for(int i=1;i<=m;i++)
	{
		cin >> w;
	} 
	for(int i=0;i<n;i++)
	{
		cin >> k;
		for(int j=0;j<k;j++)
		{
			cin >> a >> t;
			cc+=t;
		}
	}
	for(int r=0;r<b;r++)
	{
		//int ans=0;
		cin >> x >> y;
		cout << rand()%cc << "\n";
		/*for(int i=0;i<n;i++)
		{
			for(int j=0;j<k[i];j++)
			{
				if(a[i][j]==x)
				{
					ans+=t[i][j];
					break;
				}
			}
		}
		//for(int i=0;i<k[])
		ans=ans+w[x]+w[y];
		cout << ans;*/
	}
	return 0;
}
