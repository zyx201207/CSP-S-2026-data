#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
const int maxn=2e6+10;
int n,d;
int x[maxn];
int f(int a,int b,int xx,int yy)
{
	if(xx>yy)
	    return 0;
	bool flag=false;
	int ret=0;
	for(int i=1;i<=n;i++)
	{
		if(i!=a && abs(x[i]-x[a])<=d)
		    ret+=f(i,b,xx+abs(x[i]-x[a]),yy);
		if(i==b)
		{
		   	if(abs(x[i]-x[a])<=d)
		   	    ret++;
		}
	}
	return ret;
}
bool check(int a,int b)
{
	if(f(a,b,0,x[b]-x[a])==2)
	    return true;
	return false;
}
inline int read()
{
	int r=0,w=1;
	char ch=getchar();
	while(ch<'0' || ch>'9')
	{
		if(ch=='-')
		    w=-1;
		ch=getchar();
	}
	while(ch>='0' && ch<='9')
	{
		r=r*10+(ch-48);
		ch=getchar();
	}
	return r*w;
}
signed main()
{
//	ios::sync_with_stdio(false);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int C=read();
	int t=read();
	while(t--)
	{
		n=read(),d=read();
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			x[i]=read();
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				if(check(i,j)==true)
				    ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0; 
}
