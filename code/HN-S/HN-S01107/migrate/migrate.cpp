/*
3.21
特殊点对是可以传递的，如果(u,v)是特殊点，而(a,u)只有一条路径，则(a,v)也是特殊点
两个点的最短路径就是从左边的点一直往它当前能跳到的最右边的点跳，，
想一下特殊情况
x是等差数列 ， 

4.05，0思路
考虑当最小方案时，如果记录每个点能向左移动，方案还合法的点数之和sum
如果sum>1就不可能，
不对这样是错的，会漏掉，
 
我好像想到一种n^2的做法
考虑枚举每一个左端点，然后再枚举右端点，
不难发现可以把最短路程的点分成若干块的 
显然可以O(1)算出这个点的最短路程(有可能无法到达)
然后记ans[i]表示的是到达i的最短路程的方案数，当前右端点肯定只能从上一块中转移，所以双指针维护转移的左端点，
前缀和/树状数组转移即可
这里可以直接前缀和
不管了我先上个厕所

不是这大样例我也没办法调啊。
4.49
已思考 0x3f3f3f3f s
 
4.59
ok#3过了， 
现在是n^2，考虑能不能优化
 
枚举左端点，最坏情况就是任意两个点对都会选，这样必定是n^2

5.11
我发现一个性质，当左端点固定时，如果一个点能从3个点转移过来，那必定是不合法
而如果从1/2个点转移过来，如果ans之和等于2则为合法，否则为不合法
只枚举能到达的点，显然这个点之前的点必能到达，则能转移的点就是每个块的后面几个，， 

力竭了 
*/
/*
鸟为什么要迁徙？ 
*/ 
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5005+5;
int n,k;
int a[N],ans[N];
int R[N],bl[N],cnt;

signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout); 
	ios::sync_with_stdio(0);
	int T;
	cin>>T>>T;
	while(T--)
	{
		cin>>n>>k;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		sort(a+1,a+n+1);
		
		int res=0;
		for(int i=1;i<=n;i++)
		{
			for(int z=1;z<=n;z++)
			{
				ans[z] = 0;
				R[z] = 0;
			}
			cnt=1;R[0]=i;ans[i]=1;
//			cout<<i<<"-----------------"<<endl;
			for(int j=i+1;j<=n;j++)
			{
				if(a[j] - a[j-1] > k)
				{
					bl[j]=-1;
					break;
				}
				if(a[j]-a[R[cnt-1]] > k)	
				{
					R[cnt] = j-1;
					cnt++;
				}
				bl[j]=cnt;	
//				cout<<bl[j]<<' ';
			}
//			cout<<endl;
			int l=i,ir=i;
			for(int j=i+1;j<=n;j++)
			{
				if(bl[j] == -1)	break;
				if(j != i+1 && bl[j] != bl[j-1])
				{
					l=R[bl[j-1]-1]+1;
					ir = j-1;
				}
				while(l <= ir && a[j] - a[l] > k)l++;
				ans[j] = ans[ir]-ans[l-1];
//				cout<<ans[j]<<' '<<j<<' '<<l<<' '<<ir<<endl;
//				if(ans[j] > 2)	break;
				if(ans[j] == 2)
				{
					res++;
//					cout<<j<<endl;
				}
				ans[j] += ans[j-1];
			}
//			cout<<endl;
//			for(int j=i+1;j<=n;j++)	cout<<ans[j]-ans[j-1]<<' '<<j<<endl;
		}
		cout<<res<<endl;
//		return 0;
	}
	return 0;
} 
