#include<bits/stdc++.h>
#define fre(x) freopen(x".in","r",stdin);freopen(x".out","w",stdout)
using namespace std;
int main()
{
	fre("crystal");
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	long long n,m;
	cin >> n >> m;
	vector<long long> v(n+1);
	for(int i = 1;i <= n;i++)
	{
		cin >> v[i];
	}
	sort(v.begin()+1,v.end());
	vector<long long> pre(n+1);
	for(int i = 1;i <= n;i++)
	{
		pre[i] = pre[i-1]+v[i];
	}
	long long l = 1,r = 1;
	long long ma = -1;
	while(1)
	{
		while(1)
		{
			if(r > n) break;
			if(v[r]*(r-l+1) - (pre[r]-pre[l-1]) > m) break;
			ma = max(ma,r-l+1);
			r++;
		}
		l++;
		if(l > n) break;
	}
	cout << ma;
	return 0;
}