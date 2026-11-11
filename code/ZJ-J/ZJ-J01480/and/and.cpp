#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,an,a[200050],cnt;
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	for(int i=30;i>=0;i--){
		an+=1<<i;
		cnt=0;
		for(int j=1;j<=n;j++){
			if((a[j]&an)==an) cnt++;
		}
		if(cnt<m) an-=1<<i;
	}
	printf("%lld",an);
	return 0;
}