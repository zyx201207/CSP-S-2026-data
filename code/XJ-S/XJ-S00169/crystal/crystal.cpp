#include<bits/stdc++.h>
using namespace std;

long long n,m,p,ma,head=1;
long long a[600000];
bool b=true;

int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1; i<=n; i++) {
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	for(int i=2; i<=n; i++) {
		//枚举从第head项到第i项要多少修改次数
		if((p+((i-head)*(a[i]-a[i-1]))) > m) {
			//需要的次数大于m次
			//当前使用次数-head项用的次数
			while((p+((i-head)*(a[i]-a[i-1]))) > m){
				p-=(a[i-1]-a[head]);
				head++;
			}
			if(head>=i){
				i=head+1;
			}
		}
		p+=(i-head)*(a[i]-a[i-1]);
		ma=max(i-head+1,ma);
	}
	printf("%lld",ma);
	return 0;
}
//提交前把freopen注释去掉！！！
