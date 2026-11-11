#include<bits/stdc++.h>
using namespace std;
const int M=550,N=2600,NN=5000;
int c,T,n,d,a[N],dis[N][N];
int fly(int st,int en,int ti)
{
	for(int i=st;i<=en;i++)
	{
		if(dis[st][i]>d)
		{
			return fly(i,en,ti+1);
		}
	}
	return ti;
}
bool check(int x,int y)
{
	int cnt=0x3f3f3f3f;
	int anss=0;
	for(int i=x;i<=y;i++)
	{
		if(dis[x][i]>d)
			break;
		int f=fly(i,y,1);
		if(cnt==f)
		{
			anss++;
		}
		else
		{
			cnt=min(cnt,f);
			anss=0;
		}
	}
	if(anss==2)
		return true;
	return false;
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	if(c==0)
	{
		cout<<1<<'\n'<<2;
		return 0;
	}
	while(T--)
	{
		memset(dis,0,sizeof(dis));
		int ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;i++)
			{
				if(i==j)
					continue;
				dis[i][j]=dis[j]-dis[i];
				if(dis[i][j]<=d)
				if(check(i,j))
					ans++;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}//给每一条线路建虚拟点 