#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
ll m,a[500100],s[500100];

bool check(int x,int y){
	ll k = s[y] - s[x - 1];
	ll ans = 1LL * (y - x + 1) * a[y] - k;
	return ans <= m;
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i = 1;i <= n;i++){
		scanf("%lld",&a[i]);
	}
	int ma = 0;
	sort(a + 1,a + n + 1);
	for(int i = 1;i <= n;i++){
		s[i] = s[i - 1] + a[i];
	}
	for(int i = 1;i <= n;i++){
		int L = 0,R = i;
		while(L + 1 < R){
			int M = (L + R) / 2;
			if(check(M,i)){
				R = M;
			}else{
				L = M;
			}
		}
	//	if(i == 3){
	//		printf("%d ",R);
	//	}
		ma = max(ma,i - R + 1);
	}
	printf("%d\n",ma);
	return 0;
}