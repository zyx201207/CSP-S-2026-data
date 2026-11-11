#include<bits/stdc++.h>
using namespace std;
struct qj
{
	int c;
	int ed;
}xs[500005];
int cs[500005];
bool havec[300005];
int lc[300005],cnt[300005];
int main()
{
	ios::sync_with_stdio(false);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>cs[i];
		if(havec[cs[i]])
		{
			xs[lc[cs[i]]].ed=i;
			lc[cs[i]]=i;
			xs[lc[cs[i]]].c=cs[i];
			xs[lc[cs[i]]].ed=-1;
		}
		else
		{
			havec[cs[i]]=true;
			lc[cs[i]]=i;
			xs[lc[cs[i]]].c=cs[i];
			xs[lc[cs[i]]].ed=-1;
		}
	}
	for(int i=1;i<=n;i++)
	{
		int j=i;
		while(j<=n)
		{
			if(xs[j].ed!=-1)
			{
				j=xs[j].ed;
			}
			else
			{
				cnt[xs[j].c]++;
				j++;
			}
		}
	}
	
	for(int i=1;i<=m;i++)
	{
		cout<<cnt[i]<<" ";
		//printf("%d ",cnt[i]);
	}
	return 0;
}
