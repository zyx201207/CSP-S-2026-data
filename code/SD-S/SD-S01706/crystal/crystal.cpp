#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[500010];
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(ll i=1; i<=n; i++) {
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	ll f=0,less=a[2]-a[1];
	for(ll i=3; i<=n; i++) {
		if(less!=a[i]-a[i-1]) {
			f=1;
			break;
		}
	}
	if(!f) { //特判：特殊数据
		ll cnt=1, t=less;
		while(1) {
			if(t>m) {
				printf("%lld",cnt);
				return 0;
			}
			m-=t;
			t+=less;
			cnt++;
		}
	}
	ll up=1;
	for(ll i=n;; i--) {
		//cout<<i<<' '<<up<<"\n";
		if(i<=up)break;
		ll cnt=0,sum=0;
		for(ll j=i; j>=1; j--) {
			if(cnt+a[i]-a[j]>m) {
				//cout<<i<<' '<<j<<' '<<sum<<"\n";
				break;
			}
			cnt+=a[i]-a[j];
			sum++;
		}
		up=max(up,sum);
	}
	printf("%lld",up);
	return 0;
}
/*
Oct31==Dec25?
扣1复活昔涟（111111111
不不不4.7看到只有耳机的我无疑是绷不住的
无心的策划，我向你发问，倘若4.7不与翁星有关，那么费半天劲对的11.12日还有什么意义
 不，还没有结束！！！我相信星际和平播报还有4.8有转机
所以接下来我要开始许愿了：
4.8昔涟sp提前备好的大保底提前出+5.0中再次以0氪玩家之躯抽取6+1
为此，我情愿跳过5.0大版本全部角色qwq
*/
