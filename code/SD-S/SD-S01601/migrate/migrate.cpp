#include<bits/stdc++.h>
#define ll long long
#define mkp(x,y) make_pair((x),(y))
using namespace std;
const int N = 2e6+6;
int c,T,n;
ll d,a[N];
ll ans;
int getroad(int st,int ed,ll steps,ll motisp){
	if(st == ed)	return (steps == motisp) ? 1 : 0;
	if(steps >= motisp)	return 0;
	ll res = 0;
	for(int i = st+1;i <= ed;i++){
		if(a[st]+d >= a[i]){
			res += getroad(i,ed,steps+1,motisp);
			if(res > 2)	return res;
		}
	}
	return res;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&T);
	while(T--){
		ans = 0;
		scanf("%d%lld",&n,&d);
		for(int i = 1;i <= n;i++)
			scanf("%lld",&a[i]);
		for(int st = 1;st <= n;st++){
			for(int ed = st+1;ed <= n;ed++){
				if(a[ed-1]+d < a[ed])	break;
				int sp = 0;
				int i = st;
				while(i < ed){
					int j = i+1;
					while(a[i] + d >= a[j] && j <= ed){j++;}
					i = j-1;sp++;
//					printf("%d %d %d\n",st,ed,i);
				}
				int res = getroad(st,ed,0,sp);
				if(res == 2)	ans++;
				else if(res > 2)	break;
//				printf("%d %d %d %d\n",st,ed,sp,res);
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
