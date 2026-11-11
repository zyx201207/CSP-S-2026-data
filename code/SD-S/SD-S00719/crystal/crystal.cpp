#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m,ans=0,a[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int l=0,r=0,maxn=LLONG_MIN,sum=0;
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	while(l<=r&&r<=n){
		r++;
		maxn=max(maxn,a[r]);
		sum+=a[r];
		if(maxn*(r-l+1)-sum<=m){
			ans=max(ans,r-l+1);
		}else{
			sum-=a[l];
			l++;
		}
	}
	printf("%lld",ans);
	return 0;
}
/*
上午J组已经爆炸，236pts顶多 -- SD-J00972

那，我还犯不犯呢?
Yes!

Minecraft:NeoForge Loading...
Create!
Let's Create!
(机动老玩家^v^)

Paint craft Launch
(好像没拼错^v^)
PCL的下载功能(T_T)...
默哀10分钟。
龙猫我支持你!

冈易你的浮木在吗?
你举报个鸡毛! 

Mojang Studio给了你Minecraft代理权是一个错误!
Mojang不了解你!

冈易你怎么不举报官方启动器?
仗着你备了案就嚣张?
(个人猜测) 

让我们祈祷Mojang将于Minecraft 27.1 发布时将它的代理权收回，亲自下场。
打压冈易!

冈易浮木被烧了。
做用户们的怒火。
它的代理权终将变成棍木!

我的89大洋不是白花的!

试题密码:
Oct31==Dec25?

估分:
T1:AC
T2:AC?
T3:0pts
T4:0pts
Total:100pts+

山东二等稳拿!
弥补上午J组爆炸!
											临沂润盈工艺品有限公司 宣(^v^)
															2026年10月31日
																1933577
*/
