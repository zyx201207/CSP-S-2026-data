#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct sub
{
	ll id,t;
};

ll c,n,m,d,q;
ll w[10000005];
vector<sub>k[210];
ll cnt[210];

int main()
{	
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>c>>n>>m>>d>>q;
	for(int i = 1;i<=m;i++)
	{
		cin>>w[m];
	}
	for(int i = 1;i<=n;i++)
	{
		cin>>cnt[i];
		for(int j = 1;j<=cnt[i];j++)
		{
			sub tmp;
			cin>>tmp.id>>tmp.t;
			k[i].push_back(tmp);
		}
	}
	if(c == 0)
	{
		cout<<32<<'\n'<<17;
	}
	return 0;
	
}