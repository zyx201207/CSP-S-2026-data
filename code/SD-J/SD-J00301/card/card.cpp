#include<bits/stdc++.h>
using namespace std;
int n,m;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	vector<int> a(n+1),ans(m+1,0);
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		vector<int> t(n+1);
		vector<int> pos(m+1,-1);
		for(int j=1;j<=n;j++)
		{
			int k=a[j];
			if(pos[k]!=-1)
			{
				int p=pos[k];
				for(int o=p;o>t.size();o--)
				{
					pos[t[o]]=-1;
				}
				t.erase(t.begin()+p,t.end());
			}
			t.push_back(k);
			pos[k]=t.size()-1;
		}
		for(int v:t)
		{
			ans[v]++;
		}
	}
	for(int i=1;i<=m;i++)
	{
		if(i>1)
		{
			cout<<" ";
		 } 
		 cout<<ans[i];
	}
	return 0;
 } 
