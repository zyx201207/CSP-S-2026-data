#include<bits/stdc++.h>
using namespace std;

int c,n,m,dm,q,w[5000],k[5001];
vector<int> a[5001],t[5010],g[1010];
bool vis[1010];
int s,d,ans=210000;
void f(int cur,int l)
{
	if(cur==d)
	{
		ans=min(ans,l);
		return;
	}
	//cout<<l<<endl; 
	if(l>=ans)
		return;
	for(int i=0;i<(int)g[cur].size();i++)
	{ 
		int q=g[cur][i];
		for(int j=0;j<(int)a[q].size();j++)
		{
			int p=a[q][j];
			if(vis[p]==true)
				continue;
			int dd=t[q][cur]+t[q][p];
			vis[p]=true;
			f(p,l+dd);
			vis[p]=false;
		}
	}
	return;
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>dm>>q;
	for(int i=1;i<=m;i++)
		cin>>w[i];
	for(int j=1;j<=n;j++)
	{
		cin>>k[j];
		for(int i=1;i<=k[j];i++)
		{
			int a1,t1;
			cin>>a1>>t1;
			a[j].push_back(a1);
			t[j].push_back(t1);
			g[a1].push_back(j);
		}
	}
	while(q--)
	{
		cin>>s>>d;
		ans=210000;
		vis[s]=true;
		f(s,0);
		vis[s]=false;
		cout<<ans+w[s]+w[d]-1<<endl;
	}
}
