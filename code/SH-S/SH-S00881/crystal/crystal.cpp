#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;

const int N = 500005;
int n,pos,maxn = -1,curr,isequal = 1,t = 1;
long long m,sum,cnt,temp;
long long a[N],q[N];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 0;i < n;i++)
	{
		cin >> a[i];
	}
	sort(a,a+n);
	q[0] = 0;
	for(int i = 1;i < n;i++)
	{
		q[i] = a[i] - a[i-1];
	}
	for(int i = 2;i < n;i++)
	{
		if(q[i] == q[i-1])
		{
			isequal += 1;
		}
	}
	if(isequal == n-1)
	{
		long long actual = m / q[1];
		t = 1;
		while(actual >= 0 && t <= n)
		{
			actual -= t;
			t += 1;
		}
		cout << t-1 << endl;
		return 0;
	}
	pos = n-1;
	while(pos > 0)
	{
		cnt = 0;
		temp = 0;
		curr = 0;
		int i = pos;
		while(temp <= m && i >= 0)
		{
			cnt += q[i];
			temp += cnt;
			curr += 1;
			i--;
		}
		if(curr > maxn)
		{
			maxn = curr;
		}
		pos--;
	}
	cout << maxn << endl;

	return 0;
} 
