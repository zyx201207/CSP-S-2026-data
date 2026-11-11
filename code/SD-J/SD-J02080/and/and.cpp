#include<algorithm>
#include<iostream>
#include<cstring>
#include<queue>

using namespace std;

typedef long long LL;
const int N = 2e5 + 5 , MX = 35;

LL a[N] = {0};
int sum[MX] = {0};
char b[N][MX];
int f = 0;

int ch[N] = {0};

queue <int> qlist;
queue <int> r_ch;

int n , m;

LL ans = 0;

void to_b(LL x , int id)
{
	int p = 0;
	while(x != 0)
	{
		b[id][p] = char(x % 2 + '0');
		sum[p] += x % 2;
		x /= 2;
		++p;
	}
	
	return ;
	
}

void chose(int p)
{
	
	if(sum[p] == m)
	{
		for(int i = 1;i <= n;++i)
		{
			if(b[i][p] == '1')
			{
				if(ans == 0)
				{
					ans = a[i];
				}
				else
				{
					ans = ans & a[i];
				}
			}
		}
	}
	else
	{
		for(int i = 1;i <= n;++i)
		{
			if(b[i][p] == '1')
			{
				qlist.push(i);
			}
		}
		
		int cnt = sum[p];
		for(int i = p - 1;i >= 0;--i)
		{
			int q_sum = qlist.size();
			for(int j = 0;j < q_sum;++j)
			{
				int hd = qlist.front();
				qlist.pop();
				if(b[hd][i] == '1')
				{
					qlist.push(hd);
				}
				else
				{
					--cnt;
					r_ch.push(hd);
				}
			}
			if(cnt < m)
			{
				while(!r_ch.empty())
				{
					int hd = r_ch.front();
					r_ch.pop();
					qlist.push(hd);
				}
				cnt = qlist.size();
			}
			else
			{
				while(!r_ch.empty())
				{
					r_ch.pop();
				}
			}
			
			if(cnt == m)
			{
				ans = a[qlist.front()];
				qlist.pop();
				while(!qlist.empty())
				{
					ans &= a[qlist.front()];
					qlist.pop();
				}
				return ;
			}
		}

		ans = a[qlist.front()];
		qlist.pop();
		while(!qlist.empty())
		{
			ans &= a[qlist.front()];
			qlist.pop();
		}
		
	}
	return ;
}

void sol()
{
	for(int i = 1;i <= n;++i)
	{
		to_b(a[i] , i);
	}
	
	
	int flag = 0;
	int p = 0;
	for(int i = 32;i >= 0;--i)
	{
		if(sum[i] >= m)
		{
			flag = 1;
			p = i;
			break;
		}
	}
	if(flag == 0)
	{
		ans = 0;
		return ;
	}
	chose(p); 
	
	return ;
}

int main()
{
	freopen("and.in" , "r" , stdin);
	freopen("and.out" , "w" , stdout);
	
	cin >> n >> m;
	
	for(int i = 1;i <= n;++i)
	{
		cin >> a[i];
	}
	
	if(m == 1)
	{
		sort(a + 1 , a + n + 1);
		cout << a[n];
		return 0;
	}
	
	sol();
	
	cout << ans;
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
