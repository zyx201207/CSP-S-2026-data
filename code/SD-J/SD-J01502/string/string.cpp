#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
struct E{int len;char c;}a[N];
int n;
long long l,ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	if(n == 1){
		printf("0");
		return 0;
	}for (int i = 1;i <= n;i++){
		cin >> a[i].len >> a[i].c;
		l += a[i].len;
	}int ll = 1,rr = n,cnt = 0;
	long long yc = 0;
	do{
		int x = a[ll].len;
		while(x){
			if(x < a[rr].len - cnt){
				if(a[ll].c != a[rr].c) ans += x;
				cnt += x,yc += x,x = 0;
			}else{
				if(a[ll].c != a[rr].c) ans += a[rr].len - cnt;
				x -= a[rr].len - cnt,yc += a[rr].len - cnt,rr--,cnt = 0;
			}
		}ll++;
	}while(yc <= l / 2 && ll < rr);
	printf("%lld",ans);
	return 0;
}
