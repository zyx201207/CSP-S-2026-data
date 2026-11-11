//孟梓瑜 SN-J00834 西安市铁一中学 
#include <bits/stdc++.h>
using namespace std;
const int Maxn=5e5+5;
const int Maxm=3e5+5;
int p[Maxn],ans[Maxm],tbl[Maxn];//tbl:每张牌在第几个 
bool pe[Maxn];//每张牌还在不在 
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	//暴力
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>p[i];
	for(int rod=1;rod<=n;rod++)//每局 
	{
		int st=rod;//从第st张开始出牌 
		memset(tbl,0,sizeof tbl);
		memset(pe,0,sizeof pe);
		int nw=1;//此刻该放哪个位置 
		for(int i=st;i<=n;i++)
			if(pe[p[i]]==false)
				pe[p[i]]=true,tbl[p[i]]=nw,nw++;
			else
			{
				for(int j=tbl[p[i]]+1;j<nw;j++)
					pe[p[j]]=false;
				nw-=tbl[p[i]];
			}
//		cout<<"这是第"<<rod<<"局:"<<endl;
		 
		for(int i=1;i<=m;i++)
		{
			ans[i]+=pe[i];
//			cout<<pe[i]<<" ";
		}
//		cout<<endl;
					
	}
	
	for(int i=1;i<=m;i++)
		cout<<ans[i]<<" ";
	
	return 0;
}
