#include<bits/stdc++.h>//2
using namespace std;
typedef long long ll;

const int N=200+16;
const int M=5*1e5+16;


int c;
int n,m;//路线数，站点数 
int d;
int q;
ll w[M];

int x,y;

int k[N];
//ll a[N][M];
//ll t[N][M];



//map<pair<int,int>,ll> mp; 
//map<pair<int,int>,ll> dist;

int testA=1;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	
	
		for(int i=1;i<=n;i++)
		{
			cin>>k[i];
			
			for(int j=1;j<=k[i];j++)
			{
				cin>>x>>y;
			}
			
		}
		
		
		while(q--)
		{
			cin>>x>>y;
			cout<<w[x]+w[y];
			if(q) cout<<'\n';
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