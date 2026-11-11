/*
暴力
0.开long long 排序
1.确定当前水晶的能量值
2.依次考虑比它能量更低的水晶，看操作次数是否足够
3.n^2   45分
4.对于a_i=i 直接n  15分
5.对于等差数列 可以直接当前能量计算操作次数 15分
75分

当前:优化
记录当前比它更低的水晶修改到当前水晶所需操作次数
1.如果足够，那么直接记录答案
2.如果不足够，那么考虑从左端点开始减少消耗，直到足够为止

复杂度O(n) n*每个点至多经过一次l,n,共计2n
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=5e5+10;
int n,ans,l;
LL m,a[N],need;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	need=0,l=ans=1;
	for(int i=2;i<=n;i++)
	{
		need+=(a[i]-a[i-1])*(i-l+1-1);
		if(need>m)
			while(l<i&&need>m) need-=(a[i]-a[l]),l++;
		ans=max(ans,i-l+1);
	}
	printf("%d\n",ans);
	return 0;
}
