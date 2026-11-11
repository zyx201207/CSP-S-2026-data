#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,q,a[1000005],b[1000005];
int f[505][505];//我们发现具体在哪个站台不重要，直接把地铁线路看作是一个点，然后去跑floyd
vector<pair<int,int> >e[1000005];
main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int c,d;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;++i)
		cin>>a[i];//记录时间
	//接下来建边.
	for(int i=1;i<=n;++i)//
	{
		int k;
		cin>>k;
		for(int j=1;j<=k;++j)
		{
			int x,y;
			cin>>x>>y;
			e[x].push_back({i,y});
		}
	}
	memset(f,0x3f,sizeof(f));
	for(int i=1;i<=n;++i)
		f[i][i]=0;
	for(int i=1;i<=m;++i)
		for(auto j:e[i])
			for(auto k:e[i])
			{
				f[j.first][k.first]=min(j.second+k.second,f[j.first][k.first]);
			}
	for(int k=1;k<=n;++k)
		for(int i=1;i<=n;++i)
			for(int j=1;j<=n;++j)
				f[i][j]=min(f[i][k]+f[k][j],f[i][j]);
	while(q--)
	{
		int x,y;
		cin>>x>>y;
		int sum=1e18;
		for(auto j:e[x])
			for(auto k:e[y])
			{
		//		cout<<"qwq\n";
		//		cout<<j.first<<" "<<k.first<<" "<<f[15][14]<<"\n";
				sum=min(sum,f[j.first][k.first]+j.second+k.second);
			}
		cout<<sum+a[x]+a[y]<<"\n";
	}
}
//15：08


//有点困/jk，不管了不管了，最后一搏
