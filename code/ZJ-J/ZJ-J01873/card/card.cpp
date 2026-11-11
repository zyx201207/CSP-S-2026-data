#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500005],pos[300005],sum,vis[300005],ans[300005],y[300005];
vector<int> v;
signed main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		sum=0;
		for(int j=i;j<=n;j++)
		{
			vis[a[j]]++;
			if(vis[a[j]]==2)
			{
				for(int i=pos[a[j]]+1;i<=v.size();i++)
					v.pop_back();
				v.push_back(a[j]);
				sum=v.size()-1;
				pos[a[j]]=sum;
				vis[a[j]]--;
			}
			else
			{
				v.push_back(a[j]);
				pos[a[j]]=sum;
				sum++;
			}
		}
		for(int i=0;i<v.size();i++)
		{
			if(!y[v[i]])
			{
				ans[v[i]]++;
				y[v[i]]=1;
			}
		}
		v.clear();
		for(int i=1;i<=m;i++)
			y[i]=0;
	}
	for(int i=1;i<=m;i++)
		cout<<ans[i]<<" ";
	return 0;
}