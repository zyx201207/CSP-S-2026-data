#include <bits/stdc++.h>
using namespace std;
#define ll long long

int c,t;
ll n,d;
const int N=2e6+7;
ll x[N];
ll dd; 

ll read()
{
	char ch=getchar();
	ll res=0,f=1;
	while(!isdigit(ch))
	{
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(isdigit(ch))
	{
		res=res*10+ch-'0';
		ch=getchar();
	}
	return res*f;
}

int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	c=read(),t=read();
	while(t--)
	{
		n=read(),d=read();
		for(int i=1;i<=n;i++)
		{
			x[i]=read();
		}
		dd=x[n]-x[n-1];
		ll cnt=d/dd;
		if(cnt==0||cnt==1) cout<<"0\n";
		else cout<<max(n-2*cnt+1,(ll)0)<<"\n";
	}
	return 0;
}
