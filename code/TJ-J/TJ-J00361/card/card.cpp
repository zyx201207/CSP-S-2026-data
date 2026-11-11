#include<iostream>
#include <stack>
#include <algorithm>
#include <cmath>
using namespace std;
long long a[1000010];//存储原始卡牌	
long long n,m;
long long ncard[1000010];//存储桌上卡牌
long long cnt[1000010];//统计从1~i每个数字到底出现了多少次 
bool f(long long t)
{
	bool flag = 0;
	//搜索数组ncard里面有没有这个a
	for(int i = 1;i<=n;i++) 
	{
		if(ncard[i]==t)
		{
			flag =1;
			break;
		}
	}
	if(flag == 1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
long long find(long long q)
{
	for(long long i = 1;i<=n;i++)
	{
		if(ncard[i] == q)
		{
			return i;
			break;
			
		}
	}
}
int main()
{
	//stack <int> s;//栈 存储桌子上的卡牌 
	freopen("card.in","r",stdin)
	freopen("card.out","w",stdout);

	cin>>n>>m;
	//分别表示牌的数量和点数种类数。
	for(long long i = 1;i<=n;i++)
	{
		//从上到下的点数
		cin>>a[i]; 
	}
	for(long long i = 1;i<=n;i++)
	{
		//枚举局数
		for(long long j = i;j<=n;j++)
		{
			//第j局从第i张卡牌开始
			if(f(a[j])==1)
			{
				//如果桌子上有 
				//long long lw = lower_bound(ncard.begin(),ncard.end(),a[j])+1;//找到第一个等于这个数的位置 
				long long r = find(a[j]);//获取坐标 
				for(long long x = r;x<=n;x++)
				{
					ncard[x]=0;
				}
				ncard[r] = a[j]; 
			}
			else
			{
				//桌子上没有 
				ncard[j]=a[j];
			}
			 
		} 
		//一局结束 统计1~i一共出现了多少次
		for(long long j = 1;j<=n;j++)
		{
			cnt[ncard[j]]++;//cnt中的第ncard个数 出现了多少次 
		} 
	}
	for(long long i = 1;i<=n;i++)
	{
	 	cout<<cnt[i]<<" ";
	} 
	return 0;
 } 
