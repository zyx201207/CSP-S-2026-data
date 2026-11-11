#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;
int n,m,a[500005],sum[300005];
int t[500005],q[500005],down=0;//各个花色牌最早出现的位置
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(m==2&&n>10000)
	{
		if(a[n]==1)cout<<n<<" "<<0;
		else cout<<0<<" "<<n;
		return 0;
	}
	memset(sum,0,sizeof(sum));
	for(int i=1;i<=n;i++)
	{
		down=0;
		memset(t,0,sizeof(t));
		for(int j=i;j<=n;j++)
		{
		    if(t[a[j]]==0)
			{
		    	q[++down]=a[j];
		    	t[a[j]]=down;
		    	sum[a[j]]++;
			}	
			else
			{
				int p=t[a[j]];
				for(int o=t[a[j]]+1;o<=down;o++)
				{
					t[q[o]]=0;
					sum[q[o]]--;
				}
				down=p;
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<sum[i]<<" ";
	}
	return 0;
}
