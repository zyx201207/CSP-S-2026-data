#include  <bits/stdc++.h>
#define MAXN int(5e5+5)
using namespace std;
int w[MAXN];
vector<vector<pair<int,int> > > t(505);
vector<vector<bool> > mp(505,vector<bool>(505,false));

//inline void link(int u,int v,int t)
//{
//	t[u].push_back(make_pair(v,t));
//}

int main()
{
	string a;
	
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=n;i++)	cin>>w[i];
	int k;
	cin>>k;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=2*k;j++)
		{
			int a;
			cin>>a;
		//	cin>>t[i][a];
		}
	}
	
	return 0;
}

