///longlong!! 
#include<bits/stdc++.h>
#define maxn 510
#define maxm 500010
#define psbk push_back
using namespace std;
int w[maxm];
vector<int> mp_r[maxm];
vector<int> w_r[maxm];
vector<int> mp_b[maxn]; 
vector<int> w_b[maxn];
int k[maxn];
long long mp[maxn][maxn];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
		cin>>w[i];
	for(int i=1;i<=n;i++)//blue
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
		{
			int to,t;//red
			cin>>to>>t;
			mp_b[i].psbk(to);
			w_b[i].psbk(t);
			mp_r[to].psbk(i);
			w_r[to].psbk(t);
		}
	}
	/*
	for(int i=1;i<=m;i++)
	{
		cout<<i<<":\n";
		for(int j=0;j<mp_r[i].size();j++)
		{
			cout<<mp_r[i][j]<<" "<<w_r[i][j]<<"\n";
		}
		cout<<"\n";
	}
	*/
	memset(mp,0x3f,sizeof(mp));
	for(int i=0;i<=n+1;i++)
		mp[i][i]=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<mp_b[i].size();j++)
		{
			long long red=mp_b[i][j],w1=w_b[i][j];
			for(int k=0;k<mp_r[red].size();k++)
			{
				long long blue=mp_r[red][k],w2=w_r[red][k];
				mp[i][blue]=min(mp[i][blue],w1+w2);
				mp[blue][i]=min(mp[blue][i],w1+w2);
			}
		}
	}
	/*
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
			cout<<mp[i][j]<<" ";
		cout<<"\n";
	}
	*/
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				mp[i][j]=min(mp[i][j],mp[i][k]+mp[k][j]);
	/*
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
			cout<<mp[i][j]<<" ";
		cout<<"\n";
	}	
	*/
	while(q--)
	{
		int u,v;
		cin>>u>>v;
		long long minn=0x3f3f3f3f3f3f3f3f;
		for(int i=0;i<mp_r[u].size();i++)
			for(int j=0;j<mp_r[v].size();j++)
				minn=min(minn,mp[mp_r[u][i]][mp_r[v][j]]+w_r[u][i]+w_r[v][j]);
		cout<<minn+w[u]+w[v]<<"\n";
	}
	return 0;
}
/*
///min-plus 代数系统：+ =》 min ， * =》+
#include<bits/stdc++.h>
#define int long long
using namespace std;
int n;
struct block
{
	int num[550][550];
	block()
	{
		memset(num,0x3f,sizeof(num));
	}
	const int* operator[] (int x) const
	{
		return num[x];
	}
	int* operator[] (int x)
	{
		return num[x];
	}
	
};
block mp,C,D;
block operator* (const block &A,const block &B)
{
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			C[i][j]=0x3f3f3f3f3f3f3f3f;
			for(int k=1;k<=n;k++)
			{
				C[i][j]=min(C[i][j],A[i][k]+B[k][j]);
			}
		}
	}
	return C;
}
signed main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			cin>>mp[i][j];
	D=mp*mp;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			cout<<D[i][j]<<" ";
	return 0;
}

*/
