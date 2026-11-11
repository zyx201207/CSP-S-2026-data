#include <bits/stdc++.h>
using namespace std;
#define ll long long

int c,t;
int n,k;
const int N=2e6+7;

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
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	c=read(),t=read(); 
	while(t--)
	{
		n=read(),k=read();
		for(int i=1;i<n;i++)
		{
			int x,y;
			x=read(),y=read();
		}
		int m=n/2;
		int ans=ceil((m+2)*1.0/(k*1.0));
		cout<<ans<<"\n";
	}
	return 0;
}
