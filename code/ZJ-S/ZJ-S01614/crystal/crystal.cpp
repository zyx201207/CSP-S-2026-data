#include <iostream>
#include <set>
#include <map>
#define big long long
using namespace std;
big n,m,a[500005],tot,ans;
big real[500005],num[500005],sumv[500005],sum[500005];
set <big> st;
map <big,big> idx;
big find(big i)
{
	big rt = 0;
	// 下面进行寻找
	// 我们找到最靠右的一个标号
	// 使得大于该标号操作时不超过 m
	// 最终在该标号中选
	big l = 1, r = i-1, p = 0; // 如果完全可以那说明就是可以 
	while(l <= r)
	{
		big mid = (l+r)>>1;
		big need = sum[i-1]-sum[mid-1]; // 一共要改变这么多
		big val = need*real[i]; // 全部变成 real 需要这么多
		big tmp = sumv[i-1]-sumv[mid-1]; // 但是实际上只有这么多
		big delta = val-tmp; // 需要花费这么多次操作
		if(delta <= m) r = mid-1;// 操作次数在范围内，说明要找的标号在前面
		else if(delta > m)
		{
			p = mid;
			l = mid+1;
		}
	}
	// 现在我们找到了位置 p
	// 这说明前面的 p+1 ~ i-1 全部都要替换
	big M = m;
	M -= (sum[i-1]-sum[p])*real[i]-(sumv[i-1]-sumv[p]); // 花销了这么多
	rt += sum[i-1]-sum[p]; // 增加了这么多
	if(p == 0) return rt;
	else rt += (M/(real[i]-real[p]));
	return rt;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	for(big i = 1;i <= n;i++)
	{
		scanf("%lld",a+i);
		st.insert(a[i]);
	}
	// 先进行离散化
	for(auto x: st) // n log n
	{
		idx[x] = ++tot;
		real[tot] = x;
	}
	for(big i = 1;i <= n;i++) num[idx[a[i]]]++;
	// 现在进行前缀和
	// sum：num 的前缀和
	// sumv: num*real 的前缀和 
	// 由于我们已经进行排序过了
	// 所以我们直接通过二分即可找到答案 
	for(big i = 1;i <= tot;i++) 
	{
		sum[i] = sum[i-1]+num[i];
		sumv[i] = sumv[i-1]+num[i]*real[i];
	}
	for(big i = 1;i <= tot;i++) ans = max(ans,num[i]+find(i));
	printf("%lld",ans);
	return 0;
}
