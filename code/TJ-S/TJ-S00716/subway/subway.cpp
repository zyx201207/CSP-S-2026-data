#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,k,a,t,x,y,ans;
//struct line
//{
//	int a[500001];
//	int b[500001];
//}l[501];
//struct station
//{
//	long long time;
//	long long cg[501];
//}a[500001],b[500001];
long long st[500001],w[500001],st_[500001];
//bool stc[500001];

int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i=1;i<=m;i++)
	{
		cin >> w[i];
	}
	for (int i=0;i<n;i++)
	{
		cin >> k;
		for (int i=0;i<k;i++)
		{
			cin >> a >> t;
			if (st[a]>0)
			{
				st_[a]+=t;
			}
			else
			{
				st[a]+=t;
			}
			//st[a-1]+=t;
			
		}
	}
	for (int i=0;i<q;i++)
	{
		ans=0;
		cin >> x >> y;
		ans=ans+w[x]+w[y];
		for (int i=x;i<=y;i++)
		{
			if (y-x>1)
			{
				ans+=st_[i];
			}
			ans+=st[i];
			//cout << st[i] << " ";
		}
		//cout << endl;
		cout << ans <<endl;
	}
	return 0;
}
