#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,a[2000010],A,B,as,s,f;
void dfs(int q,int des,int st)
{
	if(q==des)
	{
		if(st==s)
			f++;
		if(st<s)
		{
			f=0;
			s=st;
		}
		return;
	}
	for(int i=q+1;i<=des;i++)
	{
		if(a[i]-a[q]<=d)
			dfs(i,des,st+1);
		else
			break; 
	}
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>d;
		as=0;
		for(int i=1;i<=n;i++)
			cin>>a[i];
		for(int i=3;i<=n;i++)
		{
			if(a[i-1]-a[i-2]!=a[i]-a[i-1])
				break;
			if(i==n)
				A=1;
		}
		if(A)
		{
			int x=1;
			while(d>=x*(a[2]-a[1]))
				x++;
			cout<<n-(x+x-2)+1<<'\n'; 
			continue;
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=i+3;j<=n;j++)
			{
				f=0;
				s=1e9;
				dfs(i,j,0);
				if(f==1)
					as++;
			}
		}
		cout<<as<<'\n'; 
	}
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/