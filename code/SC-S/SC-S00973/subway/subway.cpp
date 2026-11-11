#include<bits/stdc++.h>
#define int long long
using namespace std;
vector<vector<int>> a(555555),b(555555);
int c,n,m,d,q,zl=0;
int spfa(int st,int ed)
{
	vector<int> z(555555,INT_MAX);
	queue<pair<int,int>> q;
	bitset<555555> v=0;
	q.push({st,0});
	z[st]=0;
	v[st]=1;
	while(q.size())
	{
		auto p=q.front();
		q.pop();
		v[p.first]=0;
		int nm=a[p.first].size();
		for(int x=0;x<nm;x++)
		{
			int ax=p.first;
			if(z[a[ax][x]]>p.second+b[ax][x])
			{
				z[a[ax][x]]=p.second+b[ax][x];
				if(!v[a[ax][x]])
					q.push({a[ax][x],z[a[ax][x]]});
				v[a[ax][x]]=1;
			}
		}
	}
//	for(int x=0;x<=m;x++) cout<<z[x]<<' ';
//	cout<<'\n';
	return z[ed];
}
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int x=1;x<=m;x++)
	{
		int ax; cin>>ax;
		a[x].push_back(x+m);
		b[x].push_back(ax);
		a[x+m].push_back(x);
		b[x+m].push_back(ax);
	}
	zl=m*2+10;
	for(int x=0;x<n;x++)
	{
		int ak,kzl=++zl; cin>>ak;
		for(int y=0;y<ak;y++)
		{
			int ax,ay; cin>>ax>>ay;
			a[ax+m].push_back(++zl);
			b[ax+m].push_back(ay);
			a[zl].push_back(ax+m);
			b[zl].push_back(ay);
			a[zl].push_back(kzl);
			b[zl].push_back(0);
			a[kzl].push_back(zl);
			b[kzl].push_back(0);
			zl++;
		}
	}
	while(q--)
	{
		int ax,ay; cin>>ax>>ay;
		cout<<spfa(ax,ay)<<'\n';
	}
	cout<<'\n';
	return 0;
}
/*

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/