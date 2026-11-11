#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t,n,x[11],w,submin=100000,d,calc;
bool vis[11];
void getmin(int non,int d2)
{
	if(non==d2)
	{
		submin=min(submin,w);
		return;
	}
	for(int I=0;I<n;I++)
	{
		if(!vis[I] && I!=non && abs(x[I]-x[non])<=d)
		{
			vis[I]=true,w++;
			getmin(I,d2);
			vis[I]=false,w--;
		}
	}
}
void fi(int non,int d2)
{
	if(non==d2)
	{
		if(w==submin) calc++;
		return;
	}
	for(int I=0;I<n;I++)
	{
		if(!vis[I] && I!=non && abs(x[I]-x[non])<=d)
		{
			vis[I]=true,w++;
			fi(I,d2);
			vis[I]=false,w--;
		}
	}
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int T=0;T<t;T++)
	{
		cin>>n>>d;
		memset(vis,false,sizeof(vis));
		for(int I=0;I<n;I++)
		{
			cin>>x[I];
		}
		int ans=0;
		for(int I=0;I<n-1;I++)
		{
			for(int J=I+1;J<n;J++)
			{
				submin=100000;
				w=0;
				getmin(I,J);
				w=0,calc=0;
				fi(I,J);
				if(calc==2) ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
