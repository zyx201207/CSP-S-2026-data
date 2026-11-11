#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200005];
vector<int> g[55];
vector<int> c;
int cnt=0,ll;
void fen(int x)
{
	int tot=0,xx=x;
	vector<int> d;
	while(x!=0)
	{
		d.push_back(x%2);
		x/=2;
	}
	int len=d.size();
	for(int i=0;i<len;i++)
	{
		tot++;
//		cout<<d[i]<<" ";
		if(d[i]==1) g[tot].push_back(xx);
	}
//	cout<<endl;
	cnt=max(cnt,len);
}
void gclear()
{
	for(int i=1;i<=ll;i++)
	{
		while(g[i].size()) g[i].pop_back();
	}
}
void gupdate(int id)
{
	while(c.size()) c.pop_back();
	for(int x:g[id])
	{
		c.push_back(x);
	}
	gclear();
	for(int x:c)
	{
		fen(x);
	}
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		fen(a[i]);
	}
	ll=cnt;
//	cout<<ll<<endl;
	for(int i=ll;i>=1;i--)
	{
//		for(int x:g[i]) cout<<x<<" ";
//		cout<<endl;
		int l=g[i].size();
		if(l>=m)
		{
			gupdate(i);
		}
	}
	int ans=c[0],t=0;
	for(int x:c)
	{
//		cout<<x<<" ";
		ans=ans&x;
		t++;
		if(t==m) break;
	}
	cout<<ans;
	return 0;
}
