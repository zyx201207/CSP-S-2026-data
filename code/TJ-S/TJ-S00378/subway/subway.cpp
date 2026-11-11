#include <iostream>
#include <vector>
using namespace std;
#define int long long
int w[500005];
int t_of[500005][502];//站i到第j条线路还需要走<值>的时间 
signed main()
{
	freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	vector<int> statoins_of[502];
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		for(int j=0;j<k;j++)
		{
			int a,t;
			cin>>a>>t;
			t_of[a][k]=t;
			statoins_of[k].push_back(a);
		}
	}
	while(q--)
	{
		int x,y;
		cin>>x>>y;
		int ans=w[x]+w[y];
		cout<<ans+2<<"\n";
	}
	return 0;
}
