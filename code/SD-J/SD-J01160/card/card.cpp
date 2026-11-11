#include<bits/stdc++.h>
using namespace std;
int n,m,ans[10005],a[100005];
vector<int> p;
signed main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		p.resize(0);
		for(int j=i;j<=n;j++)
		{
			for(int k=0;k<p.size();k++)
			{
				if(p[k]==a[j])
				{
					while(p.size()>k) p.pop_back(); 
					//p.pop_back(); 
					break;
				 } 
			}
			p.push_back(a[j]);
		}
		for(int j=0;j<p.size();j++) ans[p[j]]++;
	 } 
	for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
	return 0;
}
