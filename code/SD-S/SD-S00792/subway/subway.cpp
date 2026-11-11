#include <iostream>
using namespace std;
int a[500005],b[505][50005],t[505][50005];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin >> c >> n >> m >> d >> q;
	int ans=0;
	for(int i=1;i<=m;i++)
	{
		cin >> a[i];
		ans+=a[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin >> b[i][0];
		for(int j=1;j<=b[i][0];j++)
		{
			cin >> b[i][j] >> t[i][j];
			ans+=b[i][j];
			ans+=t[i][j];
		}
	}
	for(int i=1;i<=q;i++)
	{
		int x,y;
		cin >> x >> y;
		if(x==y) 
		{
			cout << 0 << endl;
		}
		else
		{
			cout << ans << endl;
		}
	}
	return 0;
}
