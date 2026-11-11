//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//int a[200005],ans;
//char c[200005];
//vector<char> d;
//signed main()
//{
//	freopen("string.in","r",stdin);
//	freopen("string.out","w",stdout);
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
//	int n;
//	cin >> n;
//	for(int i = 1;i <= n;i++)
//	{
//		cin >> a[i] >> c[i];
//		while(a[i]--)
//		{
//			d.push_back(c[i]);
//		}
//	}
//	int m = d.size();
//	for(int i = 0;i < m / 2;i++)
//	{
//		if(d[i] != d[m - i - 1])
//		{
//			ans++;
//		}
//	}
//	cout << ans;
//	return 0;
//}
#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[200005],ans;
char c[200005];
vector<int> b,e;
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i] >> c[i];
		a[i] += a[i - 1];
		b.push_back(a[i]);
	}
	int d = a[n] / 2;
	for(int i = 0;i < b.size();i++)
	{
		if(b[i] > d)
		{
			b[i] = a[n] - b[i];
		}
	}
	sort(b.begin(),b.end());
	e.push_back(b[0]);
	for(int i = 1;i < b.size();i++)
	{
		if(b[i] != b[i - 1])
		{
			e.push_back(b[i]);
		}
	}
	for(int i = 0;i < e.size();i++)
	{
		int l = 1,r = n;
		while(l < r)
		{
			int mid = (l + r) / 2;
			if(a[mid] > e[i])
			{
				r = mid;
			}
			else
			{
				l = mid + 1;
			}
		}
		e[i] = a[n] - e[i];
		int l1 = 1,r1 = n;
		while(l1 < r1)
		{
			int mid = (l1 + r1) / 2;
			if(a[mid] >= e[i])
			{
				r1 = mid;
			}
			else
			{
				l1 = mid + 1;
			}
		}
		e[i] = a[n] - e[i];
		if(c[l1] != c[l])
		{
			if(i != e.size() - 1)
			{
				ans += e[i + 1] - e[i];
			}
			else
			{
				ans += d - e[i];
			}
		}
	}
	cout << ans;
	return 0;
}
