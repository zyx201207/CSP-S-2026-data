#include<bits/stdc++.h>
using namespace std;
const int m=5005;
int ce,lus,zhans,guos,huas;
long long koti[m],tim[m][m];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>ce>>lus>>zhans>>guos>>huas;
	for(int i=1;i<=zhans;i++)cin>>koti[i];
	memset(tim,31,sizeof(tim));
	for(int i=1;i<=lus;i++)
	{
		long long k,a,t;
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			cin>>a>>t;
			tim[i][a]=min(tim[i][a],t);
		}
	}
	for(int i=1;i<=zhans;i++)
		for(int j=1;j<=zhans;j++)
			for(int k=1;k<=zhans;k++)
				if(i!=j&&j!=k&&i!=k&&(tim[i][j]+tim[j][k]<tim[i][k]))
					if(tim[i][k]!=2242545357980376863)
						tim[i][k]=tim[i][j]+tim[j][k];
					else 
						tim[i][k]=tim[i][j]+tim[j][k]+tim[j][j];
	while(huas--)
	{
		int u,to,ans=0;
		cin>>u>>to;
		ans=koti[u]+koti[to]+tim[u][to]+tim[u][u];
		cout<<ans<<"\n";;
	}
	
	

	
	
	
	return 0;
}
/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
