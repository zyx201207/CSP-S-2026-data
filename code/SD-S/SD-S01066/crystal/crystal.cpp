# include<bits/stdc++.h>
# define int long long
using namespace std;
const int MX = 5e5;
int a[MX + 10];
int f[MX + 10];
int fcnt[MX + 10],v[MX + 10];
int c[MX + 10],cha[MX + 10];
int n,m,cnt;
bool check(int mid,int i)
{
	int s = f[mid] - f[i] - (v[cnt] - v[i]) * (fcnt[i - 1] - fcnt[mid - 1]);
//	cout << i << " " << mid << " " << s << endl;
	return s <= m;
}
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	sort(a + 1,a + n + 1);
	cnt = 1;
	c[cnt] = 1;
	v[cnt] = a[1];
	cha[cnt] = -1;
//	int sum = n;
	for(int i = 2;i <= n;i++)
	{
		if(a[i] != a[i - 1])
		{
			cnt++;
			v[cnt] = a[i];
			cha[cnt] = a[i] - a[i - 1];
		}
		c[cnt]++;
	}
	int sum = 0,sasa = n;
	fcnt[cnt] = sasa; 
	for(int i = cnt - 1;i >= 1;i--)
	{
		sum+=cha[i + 1];
		sasa-=c[i + 1];
		fcnt[i] = sasa;
		f[i] = f[i + 1] + sum * c[i];
	}
	/*
	for(int i = 1;i <= cnt;i++)
	{
		cout << i << ":" <<v[i] << " " << c[i] << " " << fcnt[i] << " " << f[i] << endl;
	}
	*/
	int ans = 0;
	for(int i = cnt;i >= 1;i--)
	{
		int l = 1,r = i; 
		while(l < r)
		{
			int mid = l + r >> 1;
			if(check(mid,i))
			{
				r = mid;
			}
			else
			{
				l = mid + 1;
			}
		}
//		cout << l << " ";
		int t = f[l] - f[i] - (v[cnt] - v[i]) * (fcnt[i - 1] - fcnt[l - 1]);
	//	cout << t << "------";
		t = m - t;
	//	cout << t << "----- ";
		t = (l > 1) ?  fcnt[i] - fcnt[l - 1] + t / (v[i] - v[l - 1]) : fcnt[i] - fcnt[l - 1];
//		cout << t << endl;
		ans = max(ans,t);
	 } 
	 cout << ans << endl;
	return 0;
}
