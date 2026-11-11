#include<bits/stdc++.h>
using namespace std;
int n; 
long long a[200015],cnt;
char c[200015];
struct count
{
	long long sum_a;
	char sum_c;
}p[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	cin>>a[1]>>c[1]; 
	int k=1;
	char x=c[1];
	p[1].sum_a=a[1];
	p[1].sum_c=c[1];
	for (int i=2;i<=n;i++)
	{
		cin>>a[i];
		cin>>c[i];
		if (x==c[i])
		{
			p[k].sum_a+=a[i];
		}
		else
		{
			x=c[i];
			k++;
			p[k].sum_c=c[i];
			p[k].sum_a=a[i];
		}
		
	}
	long long now=0;
	n=k;
	for (int i=1;i<=n/2;i++)
	{
		if (p[i].sum_c!=p[n-i+1].sum_c)
		{
			if (p[i].sum_a>p[n-i+1].sum_a)
			{
				p[n-i+1].sum_c=p[i].sum_c;
				cnt+=p[n-i+1].sum_a;
			}
			else
			{
				p[i].sum_c=p[n-i+1].sum_c;
				cnt+=p[i].sum_a;
			}
		}

		if (p[i].sum_c==p[n-i+1].sum_c)
		{
			now=p[i].sum_a-p[n-i+1].sum_a;

			if (now==0) continue;

			else if (now>0)
			{
				int q=n-i;
				while (now>0)
				{
					if (p[q].sum_a>=now)
					{
						if (p[i].sum_c!=p[q].sum_c)
							cnt+=now;
						p[q].sum_a-=now;
						now=0;
					}
					else
					{
						if (p[i].sum_c!=p[q].sum_c)
							cnt+=p[q].sum_a;
						now-=p[q].sum_a;
						p[q].sum_a=0;
					}
					q--;
				}
				p[n-i+1].sum_a=p[i].sum_a;
			}

			else
			{
				now*=-1;
				int q=i+1;
				while (now>0);
				{
					if (p[q].sum_a>=now)
					{
						if (p[i].sum_c!=p[q].sum_c)
							cnt+=now;
						p[q].sum_a-=now;
						now=0;
					}
					else
					{
						if (p[i].sum_c!=p[q].sum_c)
							cnt+=p[q].sum_a;
						now-=p[q].sum_a;
						p[q].sum_a=0;
					}
					q++;
				}
				p[i].sum_a=p[n-i+1].sum_a;
			}
		}
	}
	cout<<cnt;
	return 0;
}
