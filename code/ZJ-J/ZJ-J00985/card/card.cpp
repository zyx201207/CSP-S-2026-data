#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005];
vector<int>G[300005];
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		G[a[i]].push_back(i);
	}
	for(int i=1;i<=m;i++)
	{
		int kk1=G[i][G[i].size()-1],kk2=G[i][0];
		if(kk1==n)
		{
		  cout<<n<<" ";
		  continue;
		}
		bool ook=1;
		for(int j=1;j<=m;j++)
		{
			int kk3=G[j][0],kk4=G[j][G[j].size()-1];
			if(i!=j&&kk3<kk2&&kk4>kk1)
			{
			  ook=0;
			  break;
			}
		}
		if(ook)
		  cout<<kk1<<" ";
		else
		  cout<<kk2-1<<" ";
	}
	return 0;
}