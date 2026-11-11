#include<bits/stdc++.h>
using namespace std;
const int K=5e5+10;
struct stu{
	int first,second;
};
int c,n,m,d,q;
int w[K];
stu st[K][100];
long long G[510][510];//ÁÚ½Ó¾ØÕó
int cnt[K];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	memset(G,0x3f,sizeof(G));
	long long INF1=G[0][0];
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=n;i++) G[i][i]=0;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		int ki1;
		cin>>ki1;
		for(int j=1;j<=ki1;j++)
		{
			int aa1,tt1;
			cin>>aa1>>tt1;
//			cout<<i<<" "<<j<<" "<<aa1<<" "<<cnt[aa1]<<"\n";
			for(int k=1;k<=cnt[aa1];k++)
			{
//				cout<<i<<" "<<j<<" "<<k<<" "<<st[aa1][k].first<<" "<<st[aa1][k].second<<" "<<tt1<<"\n";
				G[i][st[aa1][k].first]=min(G[i][st[aa1][k].first],(long long)st[aa1][k].second+tt1);
				G[st[aa1][k].first][i]=min(G[st[aa1][k].first][i],(long long)st[aa1][k].second+tt1);
			}
			st[aa1][++cnt[aa1]].first=i;
			st[aa1][cnt[aa1]].second=tt1;
//			cout<<aa1<<" "<<cnt[aa1]<<" "<<st[aa1][cnt[aa1]].second<<"\n";
		}
	}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				G[i][j]=min(G[i][j],G[i][k]+G[k][j]);
//	for(int i=1;i<=n;i++)
//		for(int j=1;j<=n;j++)
//			cout<<i<<" "<<j<<" "<<G[i][j]<<"\n";
	for(int i=1;i<=q;i++)
	{
		int xx,yy;
		cin>>xx>>yy;
		long long ans=INF1;
		for(int i=1;i<=cnt[xx];i++)
		{
			for(int j=1;j<=cnt[yy];j++)
			{
				ans=min(ans,G[st[xx][i].first][st[yy][j].first]+st[xx][i].second+st[yy][j].second);
			}
		}
		ans=ans+w[xx]+w[yy];
		cout<<ans<<"\n";
	}
	return 0;
}
