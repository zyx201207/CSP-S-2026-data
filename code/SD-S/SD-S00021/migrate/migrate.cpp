#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,a[2000005],num,ans;
void aas(int x,int y,int u,int o,int s,int l)
{
	//x开始 y结束 u次数 o最大行驶路程 s几条 l重复几次 
	if(l>u)
		return ;
	for(int i=x;i<=y;i++)
	{
		if(a[i]-a[x]<=o&&)
		{
			aas(i,y,u,o,,l+1);
		}
		
	 } 
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int p=1;p<=t;p++)
	{
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				for(int z=1;z<=j-i;z++)
				{
					num=0;
					aas(i,j,z,d,0,1);
					if(num==2)
						ans++;
				}
			}
			cout<<ans<<endl;
		}
	}
	return 0;
 } 
 
