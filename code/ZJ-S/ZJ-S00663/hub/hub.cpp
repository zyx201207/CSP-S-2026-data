#include<bits/stdc++.h>
using namespace std;
long long rd()
{
	long long f=1,k=0;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		k=(k<<1)+(k<<3)+(c^48);
		c=getchar();
	}
	return f*k;
}
long long c,t,n,ok,k,x;
vector<int>e[2000005];
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	c=rd(),t=rd();
	while(t--)
	{
		n=rd(),k=rd();
		for(int i=1;i<n;i++)
		{
			int u=rd(),v=rd();
			e[u].push_back(v);
			e[v].push_back(u);
		}
		if(n==k)
		{
			cout<<0<<"\n";
		}
		else
		{
			n=n/2;
			x=(n-k+3)/4+1;
			cout<<x<<"\n";
//			n-k=4*(x-1);
		}
	}	
}