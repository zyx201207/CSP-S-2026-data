#include<bits/stdc++.h>
#define ull unsigned long long
#define pii pair<int,int>
using namespace std;
const int n=5e5,m=520;
int c,N,M,d,Q;
int st[n],A[n],K[n];
ull dis[n];
bool B[n];
ull T[m][m];
ull D[m][m];
ull W[m];
int L[m];
vector<int>G[n],P[m];
inline ull query(int i,int j)
{
	ull t=1e18;
	for(const int u:G[i])L[u]++,W[u]+=T[i][u]; 
//	if(i==1&&j==2)cout<<W[1]<<"-i";
	for(const int v:G[j])L[v]++,W[v]+=T[j][v];
	for(int k=1;k<=d;k++)
	{
//		if(i==1&&j==2)cout<<i<<" "<<j<<" "<<W[k]<<"\n";
		if(L[k]==2)t=W[k]<t?W[k]:t;
		L[k]=W[k]=0;
	}
	return t;
}
void work1()
{
	for(int i=1;i<=N;i++)
		cin>>st[i];
	for(int i=1;i<=M;i++)//lines
	{
		cin>>K[i];
		for(int j=1;j<=K[i];j++)//stations
		{
			cin>>A[j];
			cin>>T[A[j]][i];
			G[A[j]].push_back(i);//lines reserved
		}
	}
//	for(int i=1;i<=N;i++)for(int j:G[i])cout<<j<<" ";
	for(int i=1;i<N;i++)
	{
		for(int j=i+1;j<=N;j++)
		{
			D[i][j]=D[j][i]=query(i,j);
//			cout<<D[i][j]<<" ";
		}
//		cout<<"\n";
	}
//		cout<<"->"<<Q<<"\n";

	for(int k=1;k<=N;k++)
		for(int i=1;i<N;i++)
		{
			if(D[i][k]==1e18)continue;
			for(int j=i+1;j<=N;j++)
			{
				if(D[j][k]==1e18)continue;
				D[i][j]=D[j][i]=min(D[i][j],D[i][k]+D[j][k]);
			}
		}

//	for(int i=1;i<=N;i++){
//		for(int j=1;j<=N;j++)
//		{
//			if(D[i][j]!=1e18)cout<<D[i][j]<<"\t";
//			else cout<<"inf\t";
//		}
//		cout<<"\n";
//	}

	while(Q--)
	{
		int x,y;
		cin>>x>>y;
		cout<<D[x][y]+st[x]+st[y]<<"\n";
	}
	return;
}
void dfs(int st,int ed)
{
	queue<int>q;
	q.push(st);
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		for(int v:G[u])
		{
			if(B[v])continue;
			B[v]=1;
			dis[v]=dis[u]+1;
			if(v==ed)return;
			q.push(v);
		}
	}
	return;
}
void work2()
{
	for(int i=1;i<=N;i++)
		cin>>st[i];
	ull t1=0;
	for(int i=1;i<=M;i++)//lines
	{
//		cout<<i<<" ";
		cin>>K[i];
		for(int j=1;j<=K[i];j++)//stations
		{
//			cout<<j<<" ";
			cin>>A[j];
			cin>>t1;
			P[i].push_back(A[j]);//lines reserved
//			cout<<P[i]
		}
	}
//	cout<<Q<<"?";
	for(int i=1;i<=M;i++)
	{
		for(int j=0;j<K[i];j++)
		{
			for(int k=j+1;k<K[i];k++)
			{
				int u=P[i][j],v=P[i][k];
				G[u].push_back(v);
				G[v].push_back(u);
			}
		}
	}
	while(Q--)
	{
		for(int i=1;i<=N;i++)dis[i]=B[i]=0;
		int x,y;
		cin>>x>>y;
		dfs(x,y);
		cout<<dis[y]*t1+st[x]+st[y]<<"\n";
	}
	return;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>M>>N>>d>>Q;//m,nµﬂµπ£¨±„”⁄º∆À„ 
	if(c<=11)work1();
	else work2();
	return 0;
}

