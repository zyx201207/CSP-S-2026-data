#include <bits/stdc++.h>
#define int long long
using namespace std;
struct v
{
	int a;
	char c;
}s[200005];
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	string x = "";
	for (int i = 1;i <= n;i++)
	{
		cin >> s[i].a >> s[i].c;
		for (int j = 1;j <= s[i].a;j++)
		{
			x += s[i].c;
		}
	}
	int c = 0;
	int m = x.size();
	for (int i = 0,j = m - 1;i <= m / 2 && j >= m / 2;i++,j--)
	{
		if (x[i] != x[j])
		{
			c++;
		}
	}
	cout << c;
	return 0;
}



//#include <bits/stdc++.h>
//#define int long long
//using namespace std;
//struct v
//{
//	int a;
//	char c;
//}s[200005];
//signed main()
//{
////	freopen("string.in","r",stdin);
////	freopen("string.out","w",stdout);
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
//	int n;
//	cin >> n;
//	vector <char> v;
//	unordered_map <char,int> mp;
//	for (int i = 1;i <= n;i++)
//	{
//		cin >> s[i].a >> s[i].c;
//	}
//	char x = s[1].c;
//	int v = s[1].a;
//	int c = 0;
//	for (int i = 2;i <= n;i++)
//	{
//		if (s[i].c == x)
//		{
//			v += s[i].a;
//		}
//		else
//		{
//			mp[x] = v;
//			v.push_back(x);
//			c++;
//			x = s[i].c;
//			v = s[i].a;
//		}
//	}
//	mp[x] = v;
//	v.push_back(x);
//	c++;
//	int z = 0;
//	for (int i = 0,j = c - 1;i <= c / 2 && j >= c / 2;i++,j--)
//	{
//		if (v[i] != v[j])
//		{
//			if (mp[v[i]] == mp[v[j]])
//			{
//				z += mp[v[i]];
//			}
//			else
//			{
//				
//			}
//		}
//		else
//		{
//			if (mp[v[i]] != mp[v[j]])
//			{
//				z += abs(mp[v[i]] - mp[v[j]]);
//			}
//		}
//	}
//	cout << z;
//	return 0;
//}


//#include <bits/stdc++.h>
//#define int long long
//using namespace std;
//struct v
//{
//	int a;
//	char c;
//}ss[200005],s[200005];
//signed main()
//{
//	freopen("string.in","r",stdin);
//	freopen("string.out","w",stdout);
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
//	int n;
//	cin >> n;
//	int c = 0;
////	unordered_map <char,int> mp;
//	vector <pair<char,int> > v;
//	for (int i = 1;i <= n;i++)
//	{
//		cin >> ss[i].a >> ss[i].c;
//		c += ss[i].a;
//	}
//	int nn = 1;
//	char cc = ss[1].c;
//	int a = ss[1].a; 
//	for (int i = 2;i <= n + 1;i++)
//	{
//		if (ss[i].c != cc)
//		{
//			s[nn].c = cc;
//			s[nn].a = a;
//			nn++;
//		}
//		else
//		{
//			a += ss[i].a;
//		}
//	}
//	n = nn;
//	int ccc = 0,f = 0,x,z = 0,i;
//	for (i = 1;i <= n && !f;i++)
//	{
//		ccc += s[i].a;
//		if (cc <= c / 2)
//		{
////			mp[s[i].c] = s[i].a;
//			v.push_back({s[i].c,s[i].a});
//		}
//		else
//		{
//			if (f == 0)
//			{
//				f = 1;
//				x = ccc - c / 2;
//				if (x != s[i].a - x)
//				{
//					z += abs(s[i].a - x - x);
//				}
//			}
//		}
//	}
//	int j = n;
//	for (auto k : v)
//	{
//		if (j == i)
//		{
//			break;
//		}
//		int aa = k.second;
//		char cc = k.first;
//		if (cc != s[j].c)
//		{
//			if (aa == s[j].a)
//			{
//				z += aa;
//			}
//			else
//			{
//				z += min(aa,s[j].a);
//			}
//		}
//		else
//		{
//			if (aa != s[j].a)
//			{
//				z += abs(aa - s[j].a);
//			}
//		}
//	}
//	cout << z;
//	return 0;
//}
