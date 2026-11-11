//王昭云  西安市曲江第一学校  SN-J01173
#include <iostream>
#include <algorithm>

using namespace std;

int n,m,a[200005],ans = -0x3f3f3f3f,allnum;

bool cmp(int a,int b)
{
	return a > b;
}

int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m >> a[1];
	allnum = a[1];
	for(int i = 2;i <= n;i++)
	{
		cin >> a[i];
		allnum &= a[i];
	}
	sort(a + 1,a + n + 1,cmp);
	if(m == 1)
	{
		cout << a[1];
		
		return 0;
	}
	else if(m == n)
	{
		cout << allnum;
		return 0;
	}
	else if(m == 2)
	{
		for(int i = 1;i < n;i++)
			for(int j = i + 1;j <= n;j++)
				ans = max(ans,a[i] & a[j]);
		cout << ans;
		return 0;
	}
	cout << a[m];
	return 0;
}

