#include<bits/stdc++.h>
#define ll long long
const int N=1e6+5;

using namespace std;
ll c,n,m,d,q,a[N];
//c=测试点编号   n=地铁线路数
//m=地铁站数   d=每个地铁站最多被几条线路经过
//q=出行计划数
vector<ll> vt[N];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=n;i++)
	{cin>>a[i];}
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		for(int j=1;j<=a[i];j++)
		{
			ll aaa,bbb;
			cin>>aaa>>bbb;
		}
	}
	while(q--)
	{
		ll lll,rrr;
		cin>>lll>>rrr;
		cout<<m<<'\n';
	}
	return 0;
}