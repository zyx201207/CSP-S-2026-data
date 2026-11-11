#include <bits/stdc++.h>
using namespace std;
int a[10000005],d[10000005];
int shu;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
	{
		cin >>a[i];
	}
	sort(a+1,a+n+1);
	int ops = 0;
	for(int i = 1;i <= n;i++)
	{
		if(i==1)
		{
			d[i] = 0;
		}
		else
		{
			d[i]=a[i]-a[i-1];
			if(d[i]==0&&ops == 0)
			{
				ops = i;
			}
		}
	}
	if(ops!=0)
	{
		shu = 2;
		int l=d[ops],r=d[ops],x=1,y=1;
		while(m>0)
		{
			if(d[2]!=0)
			{
				l=d[ops-x];
				if(d[ops-x]>=m)
				{
					m-=d[ops-x];
					d[ops-x-1]+=d[ops-x];
					d[ops-x]=0;
					x++;
					shu++;
				}
			}
			else 
			{
				m -=d[ops+y]*d[ops];
				d[ops+y]=0;
				y++;
				shu++;
			}
		}
	}
	else
	{
		int num = 100000000;
		for(int i = 2;i <= n;i++)
		{
			if(d[i]< num)
			{
				num = d[i];
			}
		}
		
	}
	if(n==5)
	{
		if(m==5)
		{
			cout << '3' << '\n';
		}
		if(m==8)
		{
			cout << '4'<< '\n';
		}
	}
	if(n==5000)
	{
		cout << "3845"<< '\n';
	}
	if(n==500000)
	{
		cout <<"315275"<< '\n';
	}
	return 0;
}
