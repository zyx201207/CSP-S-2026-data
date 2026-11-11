#include<bits/stdc++.h>
using namespace std;
struct s{
	long long int start;
	long long int end;
	long long int step;
};
long long int C,T,n,d,ans,a[2000010][2000010],sr[2000010],b[2000010][2000010],z;
queue <s>q;
bool check(long long int x)
{
	for(int i=0;i<n;i++)
	{
		if(x==sr[i])
		{
			return true;
		}
	}
	return false;
}
void f()
{
	for(int i=0;i<n;i++)
	{
		q.push({sr[i],sr[i],0});
	}
	while(q.size())
	{
		s t=q.front();
		q.pop();
		if(a[t.start+z][t.end+z]>t.step)
		{
			a[t.start+z][t.end+z]=t.step;
			b[t.start+z][t.end+z]=1;
			//cout<<t.start<<' '<<t.end<<endl;
		}
		else
		{
			if(a[t.start+z][t.end+z]==t.step)
			{
				b[t.start+z][t.end+z]++;
			}
			else
			{
				continue;
			}
		}/*
		if(t.end==sr[n-1])
		{
			continue;
		}*/
		for(int i=1;i<=d;i++)
		{
			int dx=t.end+i;
			if(check(dx))
			{
				q.push({t.start,dx,t.step+i});
			}
		}
	}
	return ;
} 
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>C>>T;
	while(T--)
	{
		cin>>n>>d;
		for(int i=0;i<=n;i++)
		{
			for(int j=0;j<=n;j++)
			{
				a[i][j]=1e9;
			}
		}
		for(int i=0;i<n;i++)
		{
			cin>>sr[i];
		}
		z=abs(sr[0])-1;
		/*int flag=0,zzz=sr[1]-sr[0];
		for(int i=2;i<n;i++)
		{
			if(sr[i]-sr[i-1]!=zzz)
			{
				flag=1;
			}
		}
		if(flag==0)
		{
			cout<<0<<endl;
			continue;
		}*/
		f();
		for(int i=0;i<=n;i++)
		{
			for(int j=0;j<=n;j++)
			{
				if(b[i][j]>1)
				{
					ans++;
				}
			}
		}
		cout<<ans/3<<endl;
		while(q.size())
		{
			q.pop();
		}
		ans=0;
		for(int i=0;i<=n;i++)
		{
			for(int j=0;j<=n;j++)
			{
				b[i][j]=0;
			}
		}
	}
	return 0;
}
