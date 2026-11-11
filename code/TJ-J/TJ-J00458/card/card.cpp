#include <iostream> 
using namespace std;
int n,m,a[100000000],now[1000000],sc[1000000],ba[10000000];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    int maxx=0;
    for (int i=1;i<=n;i++)
    {
    	cin>>a[i];
	}
	for (int i=0;i<n;i++)//开始 
	{
		for (int j=1;j<=n;j++)//初始化 
		{
			now[j]=0;
			ba[j]=0;
		}
		int shu=0;
		for (int j=i+1;j<=n;j++)
		{
			if (ba[a[j]]==0)//不包含 
			{
				shu++; 
				ba[a[j]]=shu;
				now[shu]=a[j];	
				
			}
			else
			{
				shu-=ba[a[j]]+1;
				for (int k=ba[a[j]];k<=n;k++)
				{
					now[k]=0;
					ba[k]=0;
				}
				shu++; 
				ba[a[j]]=shu;
				now[shu]=a[j];	
			}
		}
		for (int k=1;k<=n;k++)
		{
			if (now[k]!=0)
			{
				sc[now[k]]++;
			}
		}
	}
	for (int i=1;i<=m;i++)
	{
		cout<<sc[i]<<" ";
	}
	return 0;
}
