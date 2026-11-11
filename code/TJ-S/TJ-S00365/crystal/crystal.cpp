#include <bits/stdc++.h>
using namespace std;
vector <long long> a;
long long s = 0,n;
int jc()
{
	set <long long> b;
	for (long long i = 0;i < a.size();i++)	b.insert(a[i]);
    return a.size()-b.size()+1;
}
void dfs(long long cry,long long m)
{
    int y = cry;
	if (m <= 0 || cry == n)
	{
		if (cry > s) s = cry;
		return;
	}
	for (long long i = 0;i < a.size();i++)
	{
		a[i]++;
		cry = jc();
		dfs(cry,m-1);
		a[i]--;
		cry = y;
	}
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long m,k;
	bool f = 1;
	cin >> n >> m;
	for (long long i = 0;i < n;i++)
	{
		long long j;
		cin >> j;
		a.push_back(j);
	}
	for (int i = 2;i < a.size();i++)	if(a[i-1]-a[i-2] != a[i]-a[i-1]) f = 0;
	if (f == 1)
	{
		int z = k;
		while(m >= 0)
		{
			m -= z;
			z += k;
			s++;
		}
		cout << s;
	}
    else
    {
		dfs(0,m);
		cout << s;
	}
	fclose(stdin);
	fclose(stdout);
    return 0;
}
