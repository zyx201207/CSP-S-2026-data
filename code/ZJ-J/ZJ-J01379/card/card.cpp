#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10,M=3e5+10;
int a[N],res[M];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		bool f[N]={false};
		vector<int> g;
		for(int j=i;j<=n;j++)
		{
			if(f[a[j]]==false)
			{
				f[a[j]]=true;
				g.push_back(a[j]);
			}
			else
			{
				int k=g.size()-1;
				while(g[k]!=a[j])
				{
					f[g[k]]=false;
					g.pop_back();
					k--;
				}
			}
		}
		for(int j=0;j<g.size();j++)
		{
			res[g[j]]++;
		}
	}
	for(int i=1;i<=m;i++) cout<<res[i]<<" ";
	return 0;
}
