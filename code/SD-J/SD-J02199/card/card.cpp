#include<bits/stdc++.h>
using namespace std;
int n,m;
int pokers[500001];
bool ison[300001];
int mhere[300001];
int zh[300001];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>pokers[i];
	for(int i=1;i<=n;i++)
	{
		memset(mhere,0,sizeof(mhere));
		memset(ison,0,sizeof(ison));
		for(int pok=i;pok<=n;pok++)
			if(mhere[pokers[pok]]==0)
			{
				ison[pokers[pok]]=true;
				mhere[pokers[pok]]=i;
			}
			else
			{
				for(int dm=mhere[pok]+1;dm<pok;dm++)
				{
					ison[pokers[dm]]=false;
					mhere[dm]=0;
				}
				mhere[pokers[pok]]=pok;
			}
		for(int pok=1;pok<=m;pok++)
			if(ison[pok]==true)
				zh[pok]++; 
	}
	zh[pokers[n]]=n;
	for(int i=1;i<=m;i++)
		cout<<zh[i]<<" ";
	return 0;
}
