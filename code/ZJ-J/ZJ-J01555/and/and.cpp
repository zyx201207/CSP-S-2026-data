#include <bits/stdc++.h>
using namespace std;

long long ans;
int a[30], maxn;// /
struct str
{
	string vs, w;
};

int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	vector<str> v;
	for(int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		string s;
		int l = 0;
		while(x)
		{
			s += x%2+'0'; // /
			x /= 2;
			l++;
		}
		maxn = max(maxn, l);
		v.push_back({s, ""});
		int j = 0;
		for(int i = 0; i < l; i++)
		{
			if(s[i] == '1')
			{
				a[i]++;
				v[v.size()-1].w += i+'0';
			}
		}
		//cout << s << endl;
	}
	for(int i = maxn-1; i >= 0; i--)
	{
		if(a[i] >= m)
		{
			//cout << endl << a[i] << endl;
			ans += pow(2, i);
			for(int j = 0; j < v.size(); j++)
			{
				if(v[j].vs.size() < i || v[j].vs[i] == '0')
				{
					//cout << '<' << j << '>';
					for(int k = 0; k < v[j].w.size(); k++)
					{
						a[v[j].w[k]-'0']--;
						if(v[j].w[k]-'0' >= i) break;
					}
				}
			}
		}
	}
	cout << ans;
	return 0;
}
