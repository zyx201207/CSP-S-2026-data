#include<bits/stdc++.h>
using namespace std;

const int N=2e6+10;

int rd()
{
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return x*f;
}

int n,d,a[N];

int c[N];
struct BIT{
	int lowbit(int x){return x&(-x);}
	int ask(int x)
	{
		int res=0;
		while(x)
		{
			res+=c[x];
			x-=lowbit(x);
		} 
		return res;
	}
	void add(int x,int v)
	{
		while(x<=n)
		{
			c[x]+=v;
			x+=lowbit(x);
		}
	}
}B;

void solve()
{
	n=rd(),d=rd();
	memset(c,0,sizeof(c));
	for(int i=1;i<=n;i++)
	{
		a[i]=rd();
		B.add(a[i],1);
	}
	
	int ans=0;
	for(int i=1;i<n;i++)
	{	
		for(int j=i+1;j<=n;j++)
		{
			if(a[j]-a[i]<=d) continue;
			
			int l=a[j]-d,r=a[i]+d;

			if(B.ask(r)-B.ask(l-1)==2)
				ans++; 
		}
	}
	cout<<ans<<"\n";
}

int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int C,T;
	C=rd(),T=rd();
	while(T--) solve();
	return 0;
}






