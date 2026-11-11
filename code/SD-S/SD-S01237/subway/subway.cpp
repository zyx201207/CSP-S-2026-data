#include<bits/stdc++.h>
using namespace std;
const int M=500005,N=505,inf=1e9;
bool l;
int c,n,m,d,q,w[M],k[N],head[N],pos[M][21];
int a[M],t[M],rk[M],nex[M],cnt,ct[M];
long long dis[N][N];
bool r;
int main()
{
	//cout<<(&l-&r)/1024.0/1024<<"MB";
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	//输入与预处理dis
	//输入 
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
		{
			cin>>a[++cnt];
			cin>>t[cnt];
			rk[cnt]=i;
			nex[cnt]=head[i];
			head[i]=cnt;
			pos[a[cnt]][++ct[a[cnt]]]=cnt;
		}
	}
	//预处理 dis
	memset(dis,0x3f,sizeof(dis));
	for(int i=1;i<=n;i++) dis[i][i]=0;
	for(int i=1;i<=m;i++)
		for(int j=1;j<=ct[i];j++)
			for(int k=j+1;k<=ct[i];k++)
			{
				int p1=pos[i][j],p2=pos[i][k];
				if(dis[rk[p1]][rk[p2]]>t[p1]+t[p2])
					dis[rk[p1]][rk[p2]]=dis[rk[p2]][rk[p1]]=t[p1]+t[p2];
			}
//	//输出中间的dis值
//	for(int i=1;i<=n;i++)
//	{
//		for(int j=1;j<=n;j++)
//			cout<<dis[i][j]<<' '; 
//		cout<<'\n';
//	}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				if(dis[i][j]>dis[i][k]+dis[k][j])
					dis[i][j]=dis[j][i]=dis[i][k]+dis[k][j];
//	//输出中间的dis值
//	for(int i=1;i<=n;i++)
//	{
//		for(int j=1;j<=n;j++)
//			cout<<dis[i][j]<<' '; 
//		cout<<'\n';
//	}	
	while(q--)
	{
		int x,y;
		long long ans=1e18;
		cin>>x>>y;
		for(int i=1;i<=ct[x];i++)
			for(int j=1;j<=ct[y];j++)
			{
				int p1=pos[x][i],p2=pos[y][j];
				long long cnt=dis[rk[p1]][rk[p2]]+t[p1]+t[p2];
				if(ans>cnt)
					ans=cnt;
			}
		cout<<(ans+w[x]+w[y])<<'\n';
	}
	return 0;
}

