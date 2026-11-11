#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5;
//priority_queue< int,vector<int>,greater<int> > q;
//struct edge{
//	int w,to,next;
//}e[N*2];
//int head[N],cnt;
//void add(int u,int v,int w)
//{
//	cnt++;
//	e[cnt].next=head[u];
//	head[u]=cnt;
//	e[cnt].to=v;
//	e[cnt].w=w;
//}
int c,n,m,d,q,k,a[N],t[N],num[N][N],qq[N][N],y[N][N],md[N],w[N],q1,q2;
void dfs(int start,int x,int to,int w)
{
	for(int wt=m;wt>=1;--wt)
	{
		if(wt==to && qq[x][wt]==1)
		{
			if(qq[start][to]==0)
			{
				num[start][to]=num[x][wt]+w;
				qq[start][to]=1;
			}
			else{
				num[start][to]=min(num[x][wt]+w,num[start][to]);
			}
		}
		if(num[x][wt]!=0 &&md[wt]>w+num[x][wt]&&wt!=start)
		{
		
			md[wt]=num[x][wt]+w;
			dfs(start,wt,to,w+num[x][wt]);
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;++i) cin>>w[i];
	for(int i=1;i<=n;++i)
	{
		cin>>k;
		for(int j=1;j<=k;++j)
		{
			cin>>a[j];
			cin>>t[a[j]];
			
			for(int z=1;z<j;z++)
			{
				if(qq[a[z]][a[j]]==1)
				{
					num[a[z]][a[j]]=min(num[a[z]][a[j]],t[a[z]]+t[a[j]]);
				}
				else{
					qq[a[z]][a[j]]=1;
					num[a[z]][a[j]]=t[a[z]]+t[a[j]];
				}
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=i+1;j<=m;j++)
		{
			if(num[i][j]==0)
			{
				for(int qwe=1;qwe<=m;++qwe)
				{
					md[qwe]=1e9;
				}
				dfs(i,i,j,0);
			}
		}
	}
	for(int i=1;i<=q;i++)
	{
		cin>>q1>>q2;
		if(q1>q2)
		{
			int uuz=q1;
			q1=q2;
			q2=uuz;
		}
		cout<<num[q1][q2]+w[q1]+w[q2]<<"\n";
	}
	return 0;
}
