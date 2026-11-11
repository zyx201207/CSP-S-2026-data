#include <bits/stdc++.h>
using namespace std;
int n;
int a[200010],b[200010];
string s,s1[200010],s2;
int x[200];
int ma=-1,sa;
int sum;
int cnt,c;
int o;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i] >> s1[i];
		o=0;
		for(int j = 1;j < i;j++)
		{
			if(s1[j] == s1[i])
			{
				b[j] = b[j] + a[i];
				o=1;
			}
		}
		if(o==0)
		{
			c++;
			b[c] = a[i];
		}
		for(int j = 1;j <= a[i];j++)
		{
			s += s1[i];
		}
		s2 = s1[i];
	}
	if(s.size() % 2 ==0)
	{
		for(int i = 1;i <= c;i++)
		{
			ma = max(ma,b[i]);
		}
		printf("%d",s.size() - ma);
		return 0;
	}
	else
	{
		for(int i = 1;i <= c;i++)
		{
			sum += b[i];
			if(sum > s.size()/2 && cnt == 0)
			{
				b[i]--;
				cnt = 1;
			}
			ma = max(ma,b[i]);
		}
		printf("%d",s.size() - ma-1);
	}
	return 0;
}
