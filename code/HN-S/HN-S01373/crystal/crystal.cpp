#include <bits/stdc++.h>
using namespace std;
int a[500005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m,ma=10e9,pos;
	cin >> n >> m;
	for(int i = 1;i <= n;i++) cin >> a[i];
	sort(a+1,a+n+1);
	int l = 1,r = 1,cnt = 1,flag = 1;
	for(int i = 1;i <= n;i++)
	{
		if(a[i]-a[i+1] < ma)
		{
			ma = a[i]-a[i+1];
			pos = i;
		}
	
	}
	while(flag)
	{
		int x = abs(a[pos-l]-a[pos]),y = abs(a[pos]-a[pos+r]);
		if(m >= min(x,y))
		{
			m -= min(x,y);
			cnt++;
			if(x>y) r++;
			else l++;
		}
		else flag = 0;
	}
	cout << cnt;
	fclose(stdin);
	fclose(stdout);
} 
