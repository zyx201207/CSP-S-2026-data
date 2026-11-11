#include<bits/stdc++.h>
using namespace std;
const int M=5e5+99;
int c,n,m,d,q;
int w[M];
int k[M];
int a[505][M];
int t[505][M];
bool f=1;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);

	cin>>c>>m>>n>>d>>q;
	
	for(int i=1;i<=n;i++)
	{
		cin>>w[i];//每个地铁站从地铁口到站厅的时间 
	}
	
	for(int i=1;i<=m;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
		{
			cin>>a[i][j]>>t[i][j];
		}
	}
	while(q--)
	{
		int st,en;
		cin>>st>>en;
		cout<<w[st]+w[en]<<endl;
	}
	return 0;
}
