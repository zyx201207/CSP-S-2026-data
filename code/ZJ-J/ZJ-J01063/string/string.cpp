#include<bits/stdc++.h>
#define int long long
using namespace std;
int n;
struct st{
	int st;
	int en;
	int k;
	char c;
} s[200005];
int xiangjiao(int s1,int e1,int s2,int e2){
	if(s1 <= s2){
		if(e1 >= e2) return e2-s2+1;
		else return max(e1-s2+1,0ll);
	}
	else{
		if(e2 < s1) return 0;
		else if(e2 >= s1 && e2 <= e1) return e2-s1+1;
		else return e1-s1+1;
	}
	return 0;
}
char get(){
	char c = ' ';
	while(c > 'z' || c < 'a') c = getchar();
	return c;
}
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i = 1;i<=n;i++) scanf("%d",&s[i].k),s[i].c = get();
	s[1].st = 1;s[1].en = s[1].k;
	for(int i = 2;i<=n;i++){
		s[i].st = s[i-1].st + s[i-1].k;
		s[i].en = s[i].st + s[i].k-1;
	}
	int to2 = n,num = s[n].en+1,ans = 0;
	for(int to1 = 1;to1 <= n;to1++){
		while(s[to2].en >= num - s[to1].en && to2 ){
			if(s[to1].c != s[to2].c)
			ans += xiangjiao(s[to2].st,s[to2].en,num-s[to1].en,num-s[to1].st);
/*			printf("%lld %lld %lld %lld = %lld\n",
			s[to2].st,
			s[to2].en,
			num-s[to1].en,
			num-s[to1].st,
			xiangjiao(s[to2].st,s[to2].en,num-s[to1].en,num-s[to1].st)
			);
*/			if(s[to2].st >= num-s[to1].en) to2--;
			else break;
		}
	}
	printf("%lld ",ans >> 1);
	return 0;
}
