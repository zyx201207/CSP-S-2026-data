#include<iostream>
#include<cmath>
#include<cstring>
#include<queue>
#include<stack>
#include<algorithm>
#include<vector>

using namespace std;

const int N=505;
const int M=5e5+5;
const long long inf=1e18+7;

int c;

int n,m;
int d,q;

long long w[M];

int k[N];
struct node
{
	int v;
	long long tim;
};
bool cmp(node a,node b)
{
	return a.v<b.v;
}
vector<node> vec[N];

vector<node> rail[M];

long long f[N][N];

int main() {
	
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	
	cin>>c;
	cin>>n>>m;
	cin>>d>>q;
	
	for(int i=1;i<=m;i++) cin>>w[i];
	
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
		{
			int v;
			long long tim;
			cin>>v>>tim;
			
			vec[i].push_back({v,tim});
			rail[v].push_back({i,tim});
		}
		
		sort(vec[i].begin(),vec[i].end(),cmp);
	}
	
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++) f[i][j]=f[j][i]=inf;
	
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			int ki=0,kj=0;
			while(ki<k[i]&&kj<k[j])
			{
				int wi=vec[i][ki].v;
				int wj=vec[j][kj].v;
				
//				cout<<i<<" "<<j<<" "<<wi<<" "<<wj<<"\n";
				
				long long timi=vec[i][ki].tim;
				long long timj=vec[j][kj].tim;
				
				if(wi==wj)
				{
					f[i][j]=min(f[i][j],timi+timj);
					f[j][i]=min(f[j][i],timi+timj);
					
					ki++;
					kj++;
				}
				else
				{
					if(wi<wj) ki++;
					else kj++;
				}
			}
		}
	}
	
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
			{
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
				f[j][i]=min(f[j][i],f[j][k]+f[k][i]);
			} 
	/*
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cout<<i<<" "<<j<<" "<<f[i][j]<<"\n";
		}
	}
	*/
	while(q--)
	{
		int u,v;
		cin>>u>>v;
		
		long long ans=inf; 
		
		for(auto railu:rail[u])
		{
			for(auto railv:rail[v])
			{
				long long s=railu.tim+railv.tim+f[railu.v][railv.v];
				
				ans=min(ans,s);
			}
		}
		
		ans+=w[u]+w[v];
		cout<<ans<<"\n";
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
