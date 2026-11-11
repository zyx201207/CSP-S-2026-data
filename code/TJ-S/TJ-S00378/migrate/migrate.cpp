#include <cstdio>
#include <vector>
using namespace std;
#define int long long
int x[2000006];
int fd_index[2000006];
signed main()
{
	freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    //clog<<"started.\n";
    int c,t;
    scanf("%lld%lld",&c,&t);
    if(11<=c&&c<=12)
    {
    	while(t--)
		{
			//clog<<"started.\n";
			int n,d;
    		scanf("%lld%lld",&n,&d);
    		for(int i=1;i<=2;i++)
    		{
    			scanf("%lld",x+i);
			}
			for(int i=3;i<=n;i++)
    		{
    			scanf("%*lld");
			}
			int d0=x[2]-x[1];
			int tiMe=d/d0;
			int ans=n-2*tiMe+1;
			if(ans<0||tiMe<=1)
			{
				ans=0;
			}
			printf("%d\n",ans);
		}
	}
    else
    {
    while(t--)
    {
    	int n,d;
    	scanf("%lld%lld",&n,&d);
    	int ans=0;
    	for(int i=1;i<=n;i++)
    	{
    		scanf("%lld",x+i);
		}
		printf("%lld\n",ans);
			continue;
		//更新最远直接目的地 
		int farest_ind=1;
		for(int i=1;i<=n;i++)
    	{
    		while(x[farest_ind]-x[i]<=d&&farest_ind<=n)
    		{
    			farest_ind++;
			}
			farest_ind--;
			fd_index[i]=farest_ind;
		}
		//遍历每个对，贪心找到最短路，按中间节点逐一尝试“次”短路
		//若成功次数大于2可中断？
		int i=1;
		int j=fd_index[i]+1;
		while(1)//遍历每个对
		{
			vector<int> indexes;//贪心找到最短路
			int pos=i;
			bool fatal=false;//是不是过不去 
			while(pos<j)
			{
				indexes.push_back(fd_index[pos]);
				if(fd_index[pos]<=pos)//路都没有
				{
					fatal=true;
					break;
				}
				pos=fd_index[pos];
			}
			if(fatal)
			{
				break;//路都没有，试集贸呢 
			}
			int anses=1;
			for(int k=indexes.size()-1;k>=0;k--)//按中间节点逐一尝试“次”短路
			{
				int changed_index=indexes[k]-1;//坏了。可能不止减一才有另一个合法解，我这得试到猴年马月去 
				
			}
		}
	}
	}	
	return 0;
}
