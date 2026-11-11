//开篇点题引发读者阅读兴趣(我要写小作文了
#include <bits/stdc++.h>
using namespace std;
long long n,m,a[500010];
bool check(long long x){
	int sum = 0;
	for(int i = 1;i <= x;i++)
		sum += a[x] - a[i];
	return sum <= m;
}
int main(){
//	freopen("crystal.in","r",stdin);
//	freopen("crystal.out","w",stdout);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i = 1;i <= n;i++)
		scanf("%lld",&a[i]);
	printf("\n1");
	sort(a + 1,a + n + 1);
	long long l = 0,r = n + 1;
	while(l + 1 < r){
		int mid = (l + r) / 2;
		if(check(mid))
			l = mid;
		else
			r = mid;
	}
	printf("%lld",l);
}
//nm迷惑行为大赏提前预订
//小作文在t4 hub
