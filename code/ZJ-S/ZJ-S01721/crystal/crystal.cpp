#include<bits/stdc++.h> 
using namespace std;
long long n,m;
long long s=0;
long long a[500010],b[500010],c[500010];
//Oct31==Dec25?
long long dfs(int k,int i)
{
	long long l=i;
	for(int j=1;j<=n;j++)
	{
		b[j]=c[j];
	}
	while(k>=0&&i<=n)
	{
		k-=b[i];
		b[i]=b[i+1];
		int j=i;
		while(b[j]==b[i])
		{
			j++;
		}
		j--;
		//cout<<j<<" "<<b[i]*(j-l+1)<<'\n';
		if(b[i]*(j-l+1)<=k)
		{
			b[j]=b[i]*(j-l+1);
			i=j;
		}
		else
		{
			return j-l+1;
		}
	}
	return n-l+1;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	int fl=1;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]!=i) fl=0;
		
	}
	sort(a+1,a+n+1);
	if(fl==0)
	{
		for(int i=1;i<=n;i++)
		{
			b[i]=a[i+1]-a[i];
			c[i]=b[i];
		}
		b[n]=0;
		c[n]=b[n];
		for(int i=1;i<=n;i++)
		{
			s=max(s,dfs(m,i));
		}
		cout<<s;
	}
	else
	{
		for(int i=1;i<=n;i++)
		{
			b[i]=i*(i-1)/2;
			if(b[i]==m)
			{
				cout<<i;
				break;
			}
			else if(b[i-1]<m&&m<b[i])
			{
				cout<<i-1;
				break;
			}
		}
	}
	return 0;
}