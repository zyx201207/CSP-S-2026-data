#include <bits/stdc++.h>
#define ll long long
using namespace std;
int a[200010][35];
ll x[200010];
int la[200010];
bool f[200010];
int cnt[200010],cntz;
bool aaaaaaaaaa;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i = 1;i<=n;i++)
	{
		f[i] = true;
		cin>>x[i];
		ll xxxxx = x[i];
		int b[35] = {0};
		while(x[i]>0)
		{
			b[++la[i]] = x[i]%2;
			x[i] /= 2;
		}
		x[i] = xxxxx;
		for(int j = 1;j<=30;j++)
		{
			a[i][j] = b[31-j];
		}
	}
//	for(int i = 1;i<=n;i++)
//	{
//		for(int j = 1;j<=30;j++)
//		{
//			cout<<a[i][j];
//		}
//		cout<<endl;
//	}
	aaaaaaaaaa = false;
	ll jg = 0;
	int j = 1;
	while(j<=30)
	{
		for(j;j<=30;j++)
		{
			cntz = 0;
			for(int i = 1;i<=n;i++)
			{
				if(a[i][j]==1&&f[i]==true)
				{
					cnt[++cntz] = i;
				}
			}
			if(cntz<m) continue;
			aaaaaaaaaa = true;
			if(cntz>=m)
			{
				int cishu = 30-j;
				ll he = 1;
				while(cishu--)
				{
					he = he*2;
				}
				jg += he;
				int a1 = 1,a2 = 1;
				while(a1<=cntz&&a2<=n)
				{
					if(cnt[a1]!=a2)
					{
						f[a2] = false;
						a2++;
					}
					else if(cnt[a1]==a2) a1++,a2++;
				}
			}
//			cout<<cntz<<" ";
//			for(int i = 1;i<=cntz;i++)
//			{
//				cout<<cnt[i]<<" "; 
//			}
//			cout<<endl;
//			cout<<j<<" ";
//			for(int i = 1;i<=n;i++)
//			{
//				cout<<f[i];
//			}
//			cout<<endl;
		}
		if(aaaaaaaaaa==false)
		{
			cout<<0;
			return 0;
		}
	}
	cout<<jg;
	
	return 0;
	
}
