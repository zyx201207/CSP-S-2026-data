#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;ll m;
ll a[510000];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i = 1;i <= n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a + 1,a + n + 1);
	ll nd = 0;
	bool flag = false;
	for(int i = 2;i <= n;i++){
		nd += (a[i] - a[i - 1]) * (i - 1);
		if(nd > m){
			printf("%d",i - 1);
			flag = true;
			break;
		}
	}
	if(!flag){
		printf("%d",n);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
