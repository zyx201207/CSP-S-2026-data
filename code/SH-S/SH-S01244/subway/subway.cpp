#include<bits/stdc++.h>
#define PII pair<int,int>
using namespace std;
int c,n,m,di,qr,d[500005],s[500005],ex[500005],a[500005];
priority_queue<PII,vector<PII>,greater<PII>> q;
vector<PII> v[500005];
void ds(int st)
{
	memset(s,0,sizeof(s));
	memset(d,0x3f,sizeof(d));
	while(!q.empty())q.pop();
	q.push({0,st});
	d[st] = 0;
	while(!q.empty())
	{
		PII t = q.top();
		q.pop();
		int u = t.second;
		if(s[u])continue;
		s[u] = 1;
		for(auto i:v[u])
		{
			int w = i.first,k = i.second;
			if(d[u] + w < d[k])
			{
				d[k] = d[u] + w;
				q.push({d[k],k});
			}
		}
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> di >> qr;
	for(int i = 1;i <= m;i++)
	{
		cin >> ex[i];
	}
	for(int i = 1;i <= n;i++)
	{
		int k;
		cin >> k;
		for(int j = 1;j <= k;j++)
		{
			int x,y;
			cin >> x >> y;
			if(x == i)a[i] = y;
			//else
			v[i].push_back({y,x});
		}
		for(int j = 0;j < k;j++)
		{
			if(v[i][j].second == i)continue;
			v[i][j].first = v[i][j].first + a[i];
		}
	}
	
	for(int i = 1;i <= qr;i++)
	{
		int st,ed;
		cin >> st >> ed;
		ds(st);
		//cout << d[2] << endl;
		cout << d[ed] + ex[st] + ex[ed] << endl;
	}
	return 0;
}
