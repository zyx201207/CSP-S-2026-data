#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[500010];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a,a+n+1);
	int r=0;
	for(int i=2;i<=n;i++){
		int c=m,g=0;
		for(int j=i;j>0;j--){
			if(c>=a[i]-a[j]){
				c-=a[i]-a[j],g++;
			}
			else{
				break;
			}
		}
		r=max(r,g);
	}
	printf("%lld",r);
	return 0;
}
