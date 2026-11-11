#include<iostream>
#include<vector>
using namespace std;
/*int dijisktra(int f,int t)
{
	
}*/
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	int firs[m];
	for(int i=0;i<m;i++)
	{
		scanf("%d",&firs[i]);
	}
	vector<int>afte[n];
	vector<int>tim[n];
	for(int i=0,k;i<n;i++)
	{
		cin>>k;
		for(int j=0,x,y;j<k;j++)
		{
			scanf("%d%d",&x,&y);
			afte[i].push_back(x);
			tim[i].push_back(y);
		}
	}
	int rf[q];
	int ren[q];
	int lans[q];
	for(int i=0;i<q;i++)
	{
		scanf("%d%d",&rf[i],&ren[i]);
		lans[i]+=firs[rf[i]]+firs[ren[i]];
	}
	int ans[q];
	for(int _q=0;_q<q;_q++)
	{
		for(int i=0;i<n;i++)
		{
			int ti=0;
			bool fi=false,sec=false;
			for(int j=0;j<n;j++)
			{
				if(afte[i][j]==rf[_q])
				{
					fi=true;
					ti+=tim[i][j];
				}
				else if(afte[i][j]==ren[_q])
				{
					sec=true;
					ti+=tim[i][j];
				}
			}
			if(fi&&sec)
			{
				ans[i]=max(ans[i],ti);
			}
		}
		printf("%d\n",ans[_q]+lans[_q]);
	}
	return 0;
}
