#include<bits/stdc++.h>
using namespace std;
long long n, m, ans;
long long a[500005];
int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(long long i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n);
	//A
	bool is_A = 1;
	for(long long i = 1; i <= n; i++)
	{
		if(a[i] != i)
		{
			is_A = 0;
			break;
		}
	}
	//B
	bool is_B = 0;
	long long cha = a[2] - a[1];
	if(n>1)
	{
		is_B = 1;
		for(long long i = 3; i <= n; i++)
		{
			if(a[i] - a[i - 1] != cha)
			{
				is_B = 0;
				break;
			}
		}
	}
	if(is_A)
	{
		/*
		ans1 m0
		ans2 m1
		ans3 m3(+2)
		ans4 m6(+3)
		...
		*/
		if(m>0)
		{
			ans = 1;
			long long m_del = 1;
			while(m>0)
			{
				m-=m_del;
				m_del++;
				ans++;
				if(m<0)ans--;
			}
			cout << ans << endl;
			return 0;
		}else
		{
			cout << 1 << endl;
			return 0;
		}
	}if(is_B)
	{
		/*
		cha2
		5
		1 3 5 7 9
		ans1 m0
		ans2 m2
		ans3 m6(+4)
		ans4 m12(+6) ( 1(+6) 3(+4) 5(+2) 7 9 )
		*/
		if(m>0)
		{
			ans = 1;
			long long m_del = cha;
			while(m>0)
			{
				m-=m_del;
				m_del+=cha;
				ans++;
				if(m<0)ans--;
			}
			cout << ans << endl;
			return 0;
		}else
		{
			cout << 1 << endl;
			return 0;
		}
	}
	for(long long i = 2; i <=n; i++)
	{
		long long m2 = m;
		long long nc = a[i];
		long long now = i;
		long long anss = 0;
		while(1)
		{
			anss++;
			now--;
			m2-=(nc - a[now]);
			if(m2<0)
			{
				anss--; break;
			}
			if(now==1)break;
		}
		ans = max(anss, ans);
	}cout << ans+1 << endl;
	return 0;
}
