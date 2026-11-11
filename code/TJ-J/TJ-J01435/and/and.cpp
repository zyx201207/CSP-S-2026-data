#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
long long k = (1 << 30);
int n,m;
long long a[200001],ans = 0;
bool t[200001];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	while(k > 0)
	{
		int cnt = 0;
		for(int i = 1;i <= n;i++)
		{
			if(a[i] >= k&&t[i] == 0) cnt++;
		}
		if(cnt >= m)
		{
			for(int i = 1;i <= n;i++)
			{
				if(a[i] >= k&&t[i] == 0) 
				{
					if(k == 262144) cout << a[i] << endl;
					a[i] -= k;
				}
				else t[i] = 1;
			}
			ans += k;
		}
		else
		{
			for(int i = 1;i <= n;i++)
			{
				if(a[i] >= k&&t[i] == 0) 
				{
					a[i] -= k;
				}
			}
		}
		k /= 2;
	}
	cout << ans << endl;
}
