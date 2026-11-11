//QJYZ SN-S00763 YangJunnan
#include<bits/stdc++.h>
using namespace std;
const int N=5*1e5+10;
int w[N],st[500][N][2],qc[(int)1e5+1][2];
bool vis[510];
int c,n,m,d,q,k;
long long ans=1e9;
void dfs(int stt,int now,int end,long long t)
{
	if(t==0) ;
	for(int i=1;i<=n;i++)
	for(int j=1;j<=d;j++)
	{
		if(st[i][j][0]==now)
		for(int k=i;k<=d;k++)
		{
			int nxt=st[i][k][0];
			if(vis[nxt]==0)
			{
				vis[nxt]=1;
				if(stt==now) 
				{
					t+=w[stt]+st[i][j][1];
				}
				else if(nxt==end) 
				{
					t+=w[end]+st[i][end][1];
					ans=min(ans,t);
				}
				else 
				{
					t+=st[i][now][1]+st[i][nxt][1];
				}
				dfs(stt,nxt,end,t);
				vis[nxt]=0;
			}
		}
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	//DEFINE
	cin>>c>>n>>m>>d>>q;

	for(int i=1;i<=m;i++) cin>>w[i];
	
	cin>>k;
	for(int l=1;l<=n;l++)
		for(int i=1;i<=k;i++) 
			cin>>st[l][k][0]>>st[l][k][1];
			
	cin>>q;
	for(int i=1;i<=q;i++)
		cin>>qc[i][0]>>qc[i][1];
		
	//DFS
	for(int i=1;i<=q;i++)
	{
		vis[qc[i][0]]=1;
		dfs(qc[i][0],qc[i][0],qc[i][1],0);
		cout<<ans<<"\n";
	}
	return 0;
	
}
