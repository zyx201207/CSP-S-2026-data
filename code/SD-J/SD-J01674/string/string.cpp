#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10;
int n,a[N],ans;
char in[10],c[N];
signed main(){
	freopen("string.in","r",stdin);
	froepen("string.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld%s",&a[i],in+1);
		c[i]=in[1];
	}
	int r=n;
	for(int l=1;l<r;){
		if(c[l]!=c[r])ans+=min(a[l],a[r]);
		if(a[l]<a[r]){
			a[r]-=a[l];
			l++;
		}else if(a[l]>a[r]){
			a[l]-=a[r];
			r--;
		}else l++,r--;
	}
	printf("%lld\n",ans);
	return 0;
}
/*
6
100000000 a
100000000 a
100000000 a
100000000 b
100000000 b
100000000 b

*/
