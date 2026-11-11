#include <bits/stdc++.h>
using namespace std;
long long n,x[2000010],a[2000010],c,t,d,l[2000010],s1,y,sum,minn=1e9;
void find(int s,int e,int num)
{
	if(s==e)
	{
		l[s1++]=num;
		return;
	}
	for(int i=s+1;i<=e;i++)
	{
		if(x[i]-x[s]<=d)
		{
			find(i,e,num+1);
		}
	}
	return;
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++)
	{
		cin>>n>>d;
		s1=0;
		for(int j=1;j<=n;j++)
		{
			cin>>x[i];
			a[i]=x[i]-x[i-1];
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=i+2;j<=n;j++)
			{
				find(i,j,0);
				for(int i=1;i<=s1;i++)
				{
					minn=min(minn,l[i]);
				}
				for(int i=1;i<=s1;i++)
				{
					if(l[i]==minn) y++;
				}
				if(y==2) sum++;
			}
		}
		y=0;
		cout<<sum<<endl;
	}
	return 0;
}