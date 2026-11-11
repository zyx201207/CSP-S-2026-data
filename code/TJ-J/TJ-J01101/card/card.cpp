#include <bits/stdc++.h>
#include <vector>
using namespace std;
vector<int>x,y;
int n,m,len;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	int b[m+1][m+1],a[n+1],q[m+1],w[m+1],ans[n+1];
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		x.push_back(a[i]);
		y.push_back(a[i]);
		if(b[a[i]]==0)
		{
			b[a[i]][1]=i;
			q[a[i]]++;
		}
		else
		{
			b[a[i]][q[a[i]]]=i;
			q[a[i]]++;
		}
		
	}
	for(int i=1;i<=n;i++)
	{
		len=x.size();
		for(int j=i;j<=len;j++)
		{
			int e;
			cin>>e;
			w[e]+=1;
			if(w[e]==2)
			{
				x.erase(x.begin()+b[a[j]][1],x.begin()+b[a[j]][2]-1);
				len=x.size();
			}
		}
		for(int j=1;j<=len;j++)
		{
			int r=x[j];
			ans[r]++;
		}cout<<1;return 0;
		x.erase(x.begin(),x.begin()+len);
		y.erase(x.begin());
		y=x;
	}
	for(int i=1;i<=n;i++)
	{
		cout<<ans[i]<<" ";
	}
	return 0;
} 
