#include<bits/stdc++.h>
using namespace std;
long long minn=999999,a[505],vis[1005][1005],c,n,m,d,q,kang[1005][1005];
void dfs(int now,int arrive,int time){
	if(now==arrive){
		if(minn>time) minn=time;
		return;
	}
	if(kang[now][arrive]!=-1){
		if(time+kang[now][arrive]<minn) minn=time+kang[now][arrive];
		return;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=now+1;j<=arrive;j++)
		{
			if(vis[i][j]!=-1&&vis[i][now]!=-1)
			{
				int wen=vis[i][now]+vis[i][j];
				kang[now][j]=wen;
				dfs(j,arrive,wen+time);
			}
		}
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=500;i++)
	{
		for(int j=1;j<=500;j++)
		{
			vis[i][j]=-1;
			kang[i][j]=-1;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		int p;
		cin>>p;
		for(int j=1;j<=p;j++)
		{
			int t1,t2;
			cin>>t1>>t2;
			vis[i][t1]=t2;
		}
	}
	for(int i=1;i<=q;i++)
	{	
		int x,y;
		int sum=0;
		cin>>x>>y;
		sum=sum+a[x]+a[y];
		dfs(x,y,sum);
		
		cout<<minn<<"\n";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}	
