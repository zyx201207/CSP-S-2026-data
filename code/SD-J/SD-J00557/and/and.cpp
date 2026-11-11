#include <bits/stdc++.h>

using namespace std;

const int N = 2e5+5;
int a[N];

int count(int x)
{
	stack<int> s;
	while(x != 0)
	{
		s.push(x%2);
		x /= 2;
	}
	
	int cnt = 0;
	while(!s.empty())
	{
		if(s.top())
			cnt++;
		s.pop();
	}
	
	return cnt;
}

bool cmp(int x,int y)
{
	int xx = count(x);
	int yy = count(y);
	
	if(xx != yy)
		return xx > yy;
	else
		return x > y;
}

int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	int n,m;
	cin >> n >> m;
	
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	
	sort(a+1,a+n+1,cmp);
	
	int ans = a[1];
	for(int i = 2; i <= m; i++)
		ans &= a[i];
	
	cout << ans << endl;
	
	return 0;
}
