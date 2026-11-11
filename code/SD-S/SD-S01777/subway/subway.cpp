#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q;
long long to[510],in[510][510],cnt[510],dis[510][510],w[510],a[510][510],t[510][510],len[510],lasf,val;
bool judge[510];
int pd_2=true,pd_same=true;
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(dis,0x3f,sizeof(dis));
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
		cin>>w[i];
	for(int now=1;now<=n;now++)
	{
		cin>>len[now];
		if(len[now]!=2) pd_2=false;
		for(int j=1;j<=len[now];j++)
		{
			cin>>a[now][j]>>t[now][j];
			in[a[now][j]][++cnt[a[now][j]]]=now;
			if(t[now][j]!=t[now][j-1]) pd_same=true;
			
		}
		for(int i=1;i<=len[i];i++)
		{
			for(int j=i+1;j<=len[i];j++)
			{
				dis[a[now][i]][a[now][j]]=t[now][i]+t[now][j];
				dis[a[now][j]][a[now][i]]=t[now][i]+t[now][j];
				val=t[now][i];
			}
		}
	}
	if(pd_2)
	{
		for(int i=1;i<=m;i++)
			for(int j=1;j<=m;j++)
				for(int k=1;k<=m;k++)
					if(i!=j&&j!=k)
					{
						dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
						dis[j][i]=dis[i][j];	
					}
		while(q--)
		{
			int from,to;
			cin>>from>>to;
	//		cout<<dis[from][to]<<endl;
			cout<<dis[from][to]+w[from]+w[to]<<'\n';
		}
		return 0;		
	}
	if(pd_same)
	{
		while(q--)
		{
			int from,to,now,bei=1,nn;
			bool flag=false;
			cin>>from>>to;
			cout<<w[from]+w[to]+2*val;
		}
		return 0;
	}
	return 0;
 } 
 /*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6 
2 3
 */
