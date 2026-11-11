#include<bits/stdc++.h>
using namespace std;
const int MAXN=500005;
long long a[MAXN];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,ans;
	scanf("%lld",&n);
	scanf("%lld",&m);
	for(long long i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	long long lst=1,used=0;
	for(long long i=2;i<=n;i++){
		
		used=used+(i-lst)*(a[i]-a[i-1]);
		while(used>m && used>=0){
			used-=(a[i]-a[lst]);
			lst++;
		}
		if(used<0){
			used=0;
			lst=i;
		}
		ans=max(ans,(i-lst+1));
	}
	printf("%lld",ans);
	return 0;
}