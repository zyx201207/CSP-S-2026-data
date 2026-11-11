#include<bits/stdc++.h>
using namespace std;
long long n;
struct node
{
	long long c;
	char a;
}m[1000005];
node op[1000005];
long long sum1 = 0, sum2 = 0;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	
	for(int i = 1; i <= n; i ++)
	{
		cin>>m[i].c>>m[i].a;
		op[i].a = m[i].a;
		op[i].c = m[i].c;
	}
	long long l = 1, r = n;
	
	while(l < r)
	{
		if(op[l].a != op[r].a)
		{
			if(op[l].c <= op[r].c)
			{
				op[r].c -= op[l].c;
				sum1 += op[l].c;
				if(op[r].c == 0)
					r--;
				l++;
			}
			else
			{
				r--;
				op[l].c -= op[r].c;
				sum1 += op[r].c;
			}
		}
		else
		{
			if(op[l].c < op[r].c)
			{
				op[r].c -= op[l].c;
				l++;
				op[l].c = 0; 
			} 
			else
			if(op[l].c > op[r].c)
			{
				op[l].c -= op[r].c;
				r--;
				op[r].c = 0;
			}
			else
			{
				l++, r--;
				op[l].c = op[r].c = 0;
			}
		}
	}
	l = 1, r = n;
	while(l < r)
	{
		if(m[l].a != m[r].a)
		{
			if(m[l].c <= m[r].c)
			{
				m[r].c -= m[l].c;
				sum2 += m[l].c;
				if(m[r].c == 0)
					r--;
				l++;
			}
			else
			{
				r--;
				m[l].c -= m[r].c;
				sum2 += m[r].c;
			}
		}
		else
		{
			if(m[l].c < m[r].c)
			{
				m[r].c -= m[l].c;
				l++;
				m[l].c = 0; 
			} 
			else
			if(m[l].c > m[r].c)
			{
				m[l].c -= m[r].c;
				r--;
				m[r].c = 0;
			}
			else
			{
				l++, r--;
				m[l].c = m[r].c = 0;
			}
		}
	}
	cout<<min(sum1, sum2);
	return 0;
 } 
