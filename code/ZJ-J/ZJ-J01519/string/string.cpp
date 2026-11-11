#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;
int n;
int a[N];
char b[N];

bool check(string x)
{
	int len = x.size();
	if(x.size() == 1) return true;
	for(int i = 0; i < len; i ++)
		if(x[i] != x[len - i - 1])
			return false;
	return true;
}

int change(string x, string y)
{
	int ans = 0;
	for(int i = 0; i < x.size(); i ++)
		if(x[i] != y[i]) ans ++;
	return ans;
}

int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	string s;
	for(int i = 1; i <= n; i ++)
	{
		cin >> a[i] >> b[i];
		for(int j = 1; j <= a[i]; j ++)
			s += b[i];
	}
	if(check(s))
	{
		cout << 0 << endl;
		return 0;
	}
	int len = s.size();
	int mid = (len - 1) / 2;
	string s1, s2;
	if(len % 2 == 0) s1 = s.substr(0, mid + 1), s2 = s.substr(mid + 1, len);
	else s1 = s.substr(0, mid), s2 = s.substr(mid + 1, len);
	cout << min(change(s1, s2), change(s2, s1)) << endl;
	return 0; 
}
