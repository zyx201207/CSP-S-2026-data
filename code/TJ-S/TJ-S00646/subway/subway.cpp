#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
int T=1;
const int N=550;
const int M=5e5+50;
const ll INF=1e18;

int c,n,m,d,q; 
ll w[M];
struct Stop_to_sub
{
	int v,dis;
};
vector<Stop_to_sub> sub_of_stop[M];
int k[N];
int _innum;
vector<int> a[N];
vector<int> t[N];
ll floyd[N][N];
int stopA,stopB;
ll ans;
void Floyd()
{
	for(int r=1;r<=n;r++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				floyd[i][j]=min(floyd[i][j],floyd[i][r]+floyd[r][j]);
			}
		}
	}
}
void solve()
{
	cin>>n>>m>>d>>q;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(i!=j)floyd[i][j]=INF;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
		{
			cin>>_innum;
			a[i].push_back(_innum);
			cin>>_innum;
			t[i].push_back(_innum);
			
			for(Stop_to_sub v:sub_of_stop[a[i][j-1]])
			{
				floyd[i][v.v]=min(floyd[i][v.v],1ll*t[i][j-1]+v.dis);
				floyd[v.v][i]=floyd[i][v.v];
			}
			sub_of_stop[a[i][j-1]].push_back({i,t[i][j-1]});
		}
	}
	Floyd();
	while(q--)
	{
		cin>>stopA>>stopB;
		ans=INF;
		for(Stop_to_sub v1:sub_of_stop[stopA])
		{
			for(Stop_to_sub v2:sub_of_stop[stopB])
			{
				ans=min(ans,floyd[v1.v][v2.v]+v1.dis+v2.dis+w[stopA]+w[stopB]);
			}
		}
		cout<<ans<<'\n';
	}
	return ;
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
//	cin>>T;
	cin>>c;
	while(T--)solve();
	return 0;
}
//in
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
//out
/*
32
17
*/

//in
/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
//out
/*
35
16
*/
