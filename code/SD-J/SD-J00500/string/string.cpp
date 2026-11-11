#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read()
{
	int x=0,y=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-')y=-1;c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		x=x*10+(c-'0');
		c=getchar();
	}
	return x*y;
}
string s;
struct node
{
	char c;
	int num;
}e[200005];
int n;
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		e[i].num=read();
		cin>>e[i].c;
		
	}
	int lnow=1,rnow=n;
	int ans=0;
	while(lnow<=rnow)
	{
		if(e[lnow].c==e[rnow].c)
		{
			if(e[lnow].num>e[rnow].num)
			{
				e[lnow].num-=e[rnow].num;
				rnow--;
			}
			else if(e[lnow].num<e[rnow].num)
			{
				e[rnow].num-=e[lnow].num;
				lnow++; 
			}
			else
			{
				e[rnow].num=0;
				e[lnow].num=0;
				lnow++; 
				rnow--;
			}
		}
		else
		{
			if(e[lnow].num>e[rnow].num)
			{
				ans+=e[rnow].num;
				e[lnow].num-=e[rnow].num;
				e[rnow].num=0;
				rnow--;
			}
			else if(e[lnow].num<e[rnow].num)
			{
				ans+=e[lnow].num;
				e[rnow].num-=e[lnow].num;
				e[lnow].num=0;
				lnow++;
			}
			else 
			{
				ans+=e[lnow].num;
				e[lnow].num=0,e[rnow].num=0;
				lnow++;
				rnow--;
			}
		}
	}
	cout<<ans;
	return 0;
}
