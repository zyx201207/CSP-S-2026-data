#include<bits/stdc++.h>
using namespace std;
int a[200005][31],b[200005];
int and1(int a,int b)
{
	int cnt = 0,i = 1;
	int l1[31],l2[31];
	while(a != 0)
	{
		l1[i] = a % 2;
		a /= 2;
		i++;
	}
	i = 1;
	while(b != 0)
	{
		l2[i] = b % 2;
		b /= 2;
		i++;
	}
	for(int i = 31;i >= 1;i--)
	{
		if(l1[i] == 1 && l2[i] == 1)
		{
			cnt = 2 * cnt + 1;
		}
		else
		{
			cnt *= 2;
		}
	}
	return cnt;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,num,max_=0;
	bool flag = 1;
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
	{
		cin >> num;
		int j = 1;
		a[i][0] = num;
		while(num != 0)
		{
			a[i][j] = num % 2;
			num /= 2;
			j++;
		}
		b[i] = i;
		max_ = max(j,max_);
	}
	for(int j = max_;j >= 1;j--)
	{
		int cnt = 0;
		int c[200005] ={};
		for(int i = 1;i <= n;i++)
		{
			if(a[b[i]][j] == 1)
			{
				cnt++;
				c[cnt] = b[i];
			}
		}
		if(cnt > m)
		{
			for(int i = 1;i <= cnt;i++)
			{
				b[i] = c[i];
			}
			n = cnt;
		}
		if(cnt == m)
		{
			int num2 = a[c[1]][0];
			for(int i = 2;i <= cnt;i++)
			{
				num2 = and1(num2,a[c[i]][0]);
			}
			cout << num2;
			flag = 0;
			break;
		}
	}
	if(flag)
	{
		cout << and1(a[b[1]][0],a[b[2]][0]);
	}
	return 0;
 } 

