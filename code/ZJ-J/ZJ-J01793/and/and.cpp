#include<bits/stdc++.h>
using namespace std;
long long ans=0,cnt=0,qwe=0,ff=0,tong[15],ans1=0;
long long n,m,q=0,g=0,linm=0,biao=0;
long long a[200005];
void dg(int x,int w)
{
	if(w==m)
	{
		ans=max(ans,cnt);
		return;
	}
	if(x==n+1) return ;
	w++;
	int f=cnt;
	if(w==1) cnt=a[x];
	else cnt=cnt&a[x];
	dg(x+1,w);
	w--;
	cnt=f;
	dg(x+1,w);
	return ;
}
bool pan(int y)
{
	long long c=0;
	while(y>1)
	{
		if(y%2!=0) return 1;
		y/=2;
		c++;
	}
	g=max(g,c);
	return 0;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		q=max(a[i],q);
		if(a[i]!=i-1) qwe++;
		if(ff==0) if(pan(a[i]+1)==1) ff==1;
		if(i==1) ans1=a[i];
		if(i>1) ans1=ans1&a[i];
	}
	if(m==1)
	{
		cout<<q;
		return 0;
	}
	if(m==n)
	{
		ans=a[1];
		for(int i=2;i<=n;i++)
		{
			ans=ans&a[i];
		}
		cout<<ans;
		return 0;
	}
	if(m==2)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				ans=max(a[i]&a[j],ans);
			}
		}
		cout<<ans;
		return 0;
	}
	if(m==n-1)
	{
		sort(a+1,a+n+1);
		for(int i=1;i<=n;i++)
		{
			long long po=a[i],mm=g,lin=0;
			while(po>0)
			{
				int u=1;
				for(int i=mm;i>0;i--)
				{
					u*=2;
				}
				if(po>=u) po-=u;
				else lin++;
				mm--;
			}
			linm=max(linm,lin);
			if(lin==max(lin,linm)) biao=i;
		}
		for(int i=1;i<=n;i++)
		{
			if(i==biao) continue;
			if(biao==1&&i==2) ans=a[i];
			else ans=ans&a[i];
		}
		cout<<ans;
		return 0;
	}
	if(n<=20)
	{
		dg(1,0);
		cout<<ans;
		return 0;
	}
	if(ff==0)
	{
		sort(a+1,a+n+1);
		cout<<a[n-m+1];
		return 0;
	}
	if(q<=4)
	{
		for(int i=1;i<=n;i++)
		{
			tong[a[i]]++;
		}
		if(tong[3]>=m) cout<<3;
		else if(tong[3]+tong[2]>=m) cout<<2;
		else if(tong[2]+tong[1]>=m) cout<<1;
		else cout<<0;
		return 0;
	}
	cout<<ans1;
	return 0;
}