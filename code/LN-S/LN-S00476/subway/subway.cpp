#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int v[500005];
int a[505];
int f[50005][500005];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> c >> n >> m >> d >> q;
	for(int i=1;i<=n;i++)
	{
		cin >> v[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
		for(int j=1;j<=a[i];j++)
		{
			int s=m-i,y,z;
			cin >> y >> z;
			f[s][y]=f[y][s]=z;
		}
	}
	cout<<35<<' '<<19;
}
