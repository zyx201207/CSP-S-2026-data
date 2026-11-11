#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
long long m,top = 1;
long long a[N];
long long ans = 1;
long long p[N];
int n;
long long minn = 1e18,maxx = -1e18;
priority_queue <int,vector<int>,greater<int>> q;
long long check(long long x,int w)
{
	long long l = w - 1,r = w,s = 0,cu = 0;
//	cout << w << " ";
	while(cu <= m)
	{
		if((x - a[l] <= a[r] - x) && ((cu + x - a[l]) <= m) && l >= 1)
		{
			cu += x - a[l];
			l --;
		}
		else if((x - a[l] > a[r] - x) && ((cu + a[r] - x) <= m) && r <= top)
		{
			cu += a[r] - x;
			r ++;
		}
		else break;
//		cout << s << " " << cu << endl;
		s ++;
	}
	return s;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin.tie(nullptr);
	cin >> n >> m;
	for(int i = 1;i <= n;i ++)
	{
		cin >> p[i];
		minn = min(minn,p[i]);
		maxx = max(maxx,p[i]);
	}
	long long md = (minn + maxx) / 2;
	for(int i = 1;i <= n;i ++)
	{
		if(p[i] > (md - m) && p[i] < (md + m)) q.push(p[i]);
	}
	top = q.size();
	for(int i = 1;i <= top;i ++)
	{
		a[i] = q.top();
		q.pop();
	}
	int w1 = 1;
	a[0] = -1e18;
	a[top + 1] = 1e18;
//	for(int i = 2;i <= top;i ++) cout << a[i] << " ";
//	cout << endl;
	long long w1p = a[1];
	for(long long i = md - (m / ans);i <= md + (m / ans);i ++)
	{
		if(i >= w1p && i != 1)
		{
			w1 ++;
			w1p = a[i];
		}
		ans = max(check(i,w1),ans);
	}
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
