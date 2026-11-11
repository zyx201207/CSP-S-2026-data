#include<iostream>
#include<map>
#include<vector>
#define ll long long
#define INF 0x3f3f3f3f
using namespace std;
int c,n,m,d,q;

int w[500005];
int k;
vector<int> a[505],t[505];

vector<pair<int,int>> zhan[500005];//che cost
ll zhuan[505][505];

int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie();cout.tie();
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)zhuan[i][j] = (i==j)?0:INF;
	for(int i=1;i<=n;i++)
	{
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			int aa,tt;
			cin>>aa>>tt;
			//a[i].push_back(aa);t[i].push_back(tt);
			for(auto kk:zhan[aa]) zhuan[i][kk.first] = zhuan[kk.first][i] = min(zhuan[i][kk.first],(ll)kk.second+tt);
			zhan[aa].push_back(make_pair(i,tt));
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int st=1;st<=n;st++)
		{
			if(zhuan[i][st]==INF)continue;
			for(int ed=1;ed<=n;ed++)
			{
				if(st==ed)continue;
				if(zhuan[i][ed]==INF)continue;
				zhuan[st][ed] = zhuan[ed][st] = min(zhuan[st][ed],zhuan[st][i]+zhuan[i][ed]);
			}
		}
	}
	while(q--)
	{
		ll st,ed,ans=INF;
		cin>>st>>ed;
		for(auto i:zhan[st])
		{
			for(auto j:zhan[ed])
			{
				ans = min(ans,zhuan[i.first][j.first]+i.second+j.second);
			}
		}
		cout<<ans+w[st]+w[ed]<<endl;
	}
	return 0;
}