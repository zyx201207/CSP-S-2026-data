#include<bits/stdc++.h>
using namespace std;
#define int long long
constexpr bool online=1;
int n,m,a[500005],sa[500005],ans;
signed main(){
	if(online)
		freopen("crystal.in","r",stdin),
		freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0); cin>>n>>m;
	for(int i=1;i<=n;++i) cin>>a[i];
	sort(a+1,a+n+1);
	/*
	就是在问执行最多 m 次 +1 之后可以生成出来多少个一样的数字
	考虑最优状态下，一个决策中的最大值一定是没有进行操作的
	于是我们枚举最大值，贪心的看他能够找多少个不大于他的元素出来
	时间复杂度 O(n\log n)，瓶颈在于排序
	*/
	for(int i=1;i<=n;++i) sa[i]=sa[i-1]+a[i];
	for(int i=1,lp=1;i<=n;++i){
		while(a[i]*(i-lp+1)-(sa[i]-sa[lp-1])>m) lp++;
		ans=max(ans,i-lp+1);
	}
	cout<<ans<<endl;
	return 0;
}
//1442 passed all samples exp 100pts
//1443 passed full check