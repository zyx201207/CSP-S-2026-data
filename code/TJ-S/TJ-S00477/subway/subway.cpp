#include<bits/stdc++.h>
using namespace std;

int transE[5005];//E.出口//H.站厅//P.站台 
int transH[5005];
int transP[5005][1005];
long long pcnt = 0;
int give(char t,int line,int sta)
{
	if(t=='E')
	{
		transE[sta] = ++pcnt;
		return pcnt;
	}
	if(t=='H')
	{
		transH[sta] = ++pcnt;
		return pcnt;
	}
	if(t=='P')
	{
		transP[line][sta] = ++pcnt;
		return pcnt;
	}
}
int trans(char t,int line,int sta)
{
	if(t=='E') return transE[sta];
	if(t=='H') return transH[sta];
	if(t=='P') return transP[line][sta];
} 
//变量定义 
int n,m,d,c,q;
//图定义
struct edge
{
	int from,to,val,next;
}E[2*5005];//QUE
long long ecnt = 0;
int head[5005];
void add(int x,int y,int val)
{
	E[++ecnt].from = x;
	E[ecnt].to = y;
	E[ecnt].val = val;
	E[ecnt].next = head[x];
	head[x] = ecnt;
}

int dist[5005][5005];

int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio();
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	//第一步：输入出口，创建站台 
	for(int i=1;i<=m;++i)
	{
		int x;
		cin>>x;
		int nH = give('H',-1,i);
		int nE = give('E',-1,i);
		add(nE,nH,x);
		add(nH,nE,x);
	}
	//第二：输入线路，站台
	//for(int i=1;i<=5;++i)
	//{
	//	cout<<transH[i]<<" ";
	//}
	
	for(int i=1;i<=n;++i) 
	{
		int xn;
		cin>>xn;
		int lastS = -1;
		for(int j=1;j<=xn;++j)
		{
			int p,t;
			cin>>p>>t;
			int nP = give('P',i,p);
			int nH = trans('H',-1,p);
			add(nP,nH,t);
			add(nH,nP,t);
			//cout<<nP<<" "<<nH<<" "<<t<<endl;
			if(lastS!=-1)
			{
				add(trans('P',i,lastS),nP,0);
				add(nP,trans('P',i,lastS),0);
			}
			lastS = p;
		}
	}
//	for(int i=1;i<=5;++i)
//	{
//		cout<<trans('P',1,i)<<" ";
//	}
//	cout<<endl;
//	for(int i=1;i<=5;++i)
//	{
//		cout<<trans('P',2,i)<<" ";
//	}
	//cout<<endl;
	//第三步：跑弗洛伊德最短路 
	memset(dist,0x3f,sizeof(dist));
	for(int i=1;i<=ecnt;++i)
	{
		dist[E[i].from][E[i].to] = E[i].val;
		dist[E[i].to][E[i].from] = E[i].val;
		dist[E[i].to][E[i].to] = 0;
		dist[E[i].from][E[i].from] = 0;
		//cout<<E[i].from<<" "<<E[i].to<<" "<<E[i].val<<endl;
	}
	for(int tt=0;tt<=pcnt;++tt)
	{
		for(int i=1;i<=pcnt;++i)
		{
			for(int j=1;j<=pcnt;++j)
			{
				for(int k=1;k<=pcnt;++k)
				{
					//if(i==j || j==k || k==i) continue;
					if(dist[i][j] > dist[i][k]+dist[k][j])
					{
						dist[i][j] = dist[i][k] + dist[k][j];
					}
					//cout<<i<<" "<<k<<" "<<dist[i][j]<<" "<<dist[j][k]<<endl;
				}
			}
		}
	}
	
	//cout<<"!"<<dist[2][6]<<" "<<dist[16][5]<<" "<<dist[5][6]<<endl;
	while(q--)
	{
		int fromS,toS;
		cin>>fromS>>toS;
		int nEf = trans('E',-1,fromS);
		int nEt = trans('E',-1,toS);
		//cout<<nEf<<"---"<<nEt<<endl;
		cout<<dist[nEf][nEt]<<'\n';		
	} 
	return 0;
} 
