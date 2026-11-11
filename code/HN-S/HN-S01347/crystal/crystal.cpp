#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+5;
long long n,m,a[maxn],s[maxn],l=1,r=2,ans=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		s[i]=s[i-1]+a[i];
	}
	sort(a+1,a+n+1);
	while(true){
		if(m>a[r]*(r-l+1)+s[l-1]-s[r]){
			r++;
			if(r==n+1){
				break;
			}
			ans=max(ans,r-l+1);
		}
		else{
			l++;
		}
	}
	printf("%lld",ans);
	return 0;
}
