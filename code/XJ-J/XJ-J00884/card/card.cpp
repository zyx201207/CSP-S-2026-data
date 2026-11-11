#include <bits/stdc++.h>
using namespace std;

typedef int itn;
const int N=500010,M=300010;
itn a[N],b[M],ans[M],n,m;
bool st[M];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(itn i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(itn i=1;i<=n;i++)
	{
		vector<int> card;
		for(int j=i;j<=n;j++)
		{         
			if(!st[a[j]])
			{
				st[a[j]]=true;
				b[a[j]]=j;
			}
			else
			{
				for(int k=b[a[j]]-1;k<card.size();k++)
				{                   
					st[card[k]]=false;
					card[k]=0;
				}
			}
			card.push_back(a[j]);
		}
		for(int i=0;i<card.size();i++)
		{
			ans[card[i]]++;
		}
	}
	for(itn i=1;i<=m;i++)
	{ 
	
		cout<<ans[i]<<" ";
	}
	return 0;
}