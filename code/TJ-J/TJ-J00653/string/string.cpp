#include<bits/stdc++.h>

std::vector<char> s;
long long n = 0;
int a[(long long) 1e5 + 10];
long long len = 0;
long long ans;
int main()
{
	std::freopen("string.in", "r", stdin);
	std::freopen("string.out", "w", stdout);
	
	char tmp;
	std::cin>>n;
	for(int i = 0 ; i < n ; i++)
	{
		std::cin>>a[i]>>tmp;
		s.insert(s.end(), a[i], tmp);
		len += a[i];
	}
	for(int i = 0 ; i < len / 2 ; i++)
	{
		if(s[i] != s[len - i - 1])
		{
			ans++;
		}
	}
	std::cout<<ans;
}

/*
#include<bits/stdc++.h>

struct asdf
{
	int xx = 0;
	int m = 0;
	int x = 0;
};
std::vector<asdf> s;
int n;
int len = 0;

int jishu()
{
	int m = 0;
	for(int i = 0 ; i < len / 2 + 1 ; i++)
	{
		if(s[m].xx - 1 > 0) s[m].xx--
		else
		{
			m++;
			s[m].xx--
		}
		
	}
	int ans;
	int m1 = 0, m2 = s.end() - s.begin() - 1;
	for(int i = 0 ; i < m ; i++)
	{
		if(m1 == m2)
		{
			break;
		}
		if(s[m1].x == s[m2].x)
		{
			if(s[m1].m > s[m2].m)
			{
				s[m1].m -= s[m2].m;
				s[m2].m = 0;
				m2--;
			}else
			{
				s[m2].m -= s[m1].m;
				s[m1].m = 0;
				m1++;
				
			}
		}else
		{
			if(s[m1].m > s[m2].m)
			{
				s[m1].m -= s[m2].m;
				ans += s[m2].m;
				s[m2].m = 0;
				m2--;
			}else
			{
				s[m2].m -= s[m1].m;
				ans += s[m1].m;
				s[m1].m = 0;
				m1++;
				
			}
		}else
		}
	}
}
int oushu
int main()
{
	std::cin>>n;
	for(int i = 0 ; i < n ; i++)
	{
		std::cin>>s[i].m>>s[i].x;
		s[i].xx = s[i].m;
		len += s[i].m;
	}
	
}
*/
