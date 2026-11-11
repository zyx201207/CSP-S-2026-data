#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,a,zongt,ans=1e18,qidian,zhongdian;
long long w[500005];//地铁口到站厅
long long k[505];//第i条线有k[i]个站点 
long long t[505][20005];//站厅到地铁站 
bool kaiqi[505];//这一条线是否用过 
void zhong1(long long qi,long long zhong)
	{
		if(qi==zhong)
		{
			ans=min(ans,zongt);
			return;
		}
		
		//判断^ 
		for(int i=1;i<=n;i++)
		{
			if(t[i][qi]!=0&&!kaiqi[i])
			{
				for(int j=1;j<=m;j++)
				{
					if(t[i][j]!=0&&j!=qi)
					{
						zongt=zongt+t[i][j]+t[i][qi]; 
						kaiqi[i]=1;
						zhong1(j,zhong);						
						kaiqi[i]=0;
						zongt=zongt-t[i][j]-t[i][qi];
					}
				}
			}
			/*if(t[i][zhong]!=0&&!kaiqi[i])
			{
				zongt+=t[i][zhong];
				for(int j=1;j<=m;j++)
				{
					if(j[i][j]!=0&&j!=m)
					{
						kaiqi[i]=1;
						zongt+=t[i][j]; 
						zong(qi,j);
						kaiqi[i]=0;
					}
				}
			}*/
			
		}
		
	}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	 for(int i=1;i<=m;i++)
	 {
	 	cin>>w[i];
	 }
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
		{cin>>a;
		cin>>t[i][a];//经过的站点有数值 
		
		}
	}
	
	for(int i=1;i<=q;i++)
	{
		ans=1e18;
		cin>>qidian>>zhongdian;
		zongt=w[qidian]+w[zhongdian];
		zhong1(qidian,zhongdian);
		cout<<ans<<endl;
	}
	return 0;
}