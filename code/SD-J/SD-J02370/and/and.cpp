#include <bits/stdc++.h>
using namespace std;
long long n,m,maxx,b[200005];
string s[200005];
void dfs(long long a,int sum,int pos)
{
	if(sum==m)
	{
		maxx=max(maxx,a);
		return;
	}
	if(pos>=n)
	{
		return ;
	}
	dfs(a&b[pos+1],sum+1,pos+1);
	dfs(a,sum,pos+1);
}
bool check(long long a)
{
	while(a%2==0)
	{
		a/=2; 
	}
	
	if(a!=1)
		return 0;
	return 1;
}
int cmp(long long a,long long b)
{
	return a>=b;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>b[i];
	}
	if(n>2000)
	{
		bool flag=true;
		for(int i=1;i<=n;i++)
		{
			if(b[i]!=i-1)
			{
				flag=false;
				break;
			}
		}
		sort(b+1,b+n+1,cmp);
		if(flag)
		{
			long long kk=b[1];
			for(int i=2;i<=m;i++)
			{
				kk&=b[i];
			}
			cout<<kk;
		}else
		{
			cout<<b[m];
		return 0;
		}
		
	}else{
		for(int i=1;i<=n;i++)
		{
			dfs(b[i],1,i);
		}
		cout<<maxx;
	}
	return 0;
}
