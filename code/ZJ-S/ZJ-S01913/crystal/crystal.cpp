#include <bits/stdc++.h>
using namespace std;
typedef long long ll ;
const int N = 5e5+58;
ll read(){
	ll x=0,f=1;char s=getchar();
	while(!isdigit(s)){
		if (s == '-') f=-1;
		s=getchar();
	}while(isdigit(s)){
		x=10ll*x+s-'0';
		s=getchar();
	}return 1ll*x*f;
}
ll a[N],s[N];
int n;
ll m;
bool check(int pos,int rgt) {
	ll sum = s[rgt] - s[pos-1];
	ll tar = 1ll*(rgt - pos + 1)*a[rgt+1];
	if (tar - sum <= m) return true;
	return false;
}
int get(int l,int r) {

	int tmp = r;
	int res = r;
	while(l<=r) {
		int mid = (l+r) >> 1;
		if (check(mid,tmp)) {
			r = mid - 1;
			res = min(res,mid);
		}else l = mid + 1;
	}
	return tmp - res + 2;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++) {
		a[i] = read();
		
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) s[i] = s[i-1] + a[i];
	int ans = 1;
	for(int i=2;i<=n;i++) {
		int l = 1, r = i-1 ;
	
		ans = max(ans,get(l,r));
	}
	printf("%d\n",ans);
	
	return 0;
}
/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7

5 5 
1 2 3 4 5

*/