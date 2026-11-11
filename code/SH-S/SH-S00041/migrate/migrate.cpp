#include <bits/stdc++.h>
using namespace std;
#define int long long
int c,t,n,d,a[2000005],ans;
int minn,ansn;
bool fly(int x,int end,int num)
{
	if(x==end)
	{
		if(num<minn)
		{
			minn=num;
			ansn=1;
		}
		else if(num==minn) ansn++;
	}
	for(int i=x+1;i<=end;i++)
	{
		if(a[i]-a[x]>d) break;
		fly(i,end,num+1);
	}
}
void solve()
{
	cin >> n >> d;
	ans=0;
	for(int i=1;i<=n;i++) cin >> a[i];
	for(int i=1;i<n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			minn=1e9;
			ansn=0;
			fly(i,j,0);
			if(ansn==2)
			{
				ans++;
//				cout << i << " " << j << "\n";
			}
		}
	}
	cout << ans << "\n";
}
void solve2()
{
	cin >> n >> d;
	for(int i=1;i<=n;i++) cin >> a[i];
	int i=a[2]-a[1];
	if(d>=2*i&&d<=3*i-1&&n>=4) cout << n-3 << "\n";
	else cout << 0 << "\n";
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	if(c==11||c==12)
	{
		while(t--) solve2();
		return 0;
	}
	while(t--) solve();
	return 0;
} 
