#include<bits/stdc++.h>
using namespace std;
int n,a[200005];
char c[200005];
long long ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d%s",&a[i],&c[i]);
	int L=1,R=n,longl=a[1],longr=a[n];
	while(L<R){
		if(c[L]==c[R]){
			if(longl==longr) L++,R--,longl=a[L],longr=a[R];
			else if(longl<longr) L++,longr=longr-longl,longl=a[L];
			else R--,longl=longl-longr,longr=a[R];
		}else{
			if(longl==longr) L++,R--,ans+=longl,longl=a[L],longr=a[R];
			else if(longl<longr) L++,ans+=longl,longr=longr-longl,longl=a[L];
			else R--,ans+=longr,longl=longl-longr,longr=a[R];
		}
	}
	printf("%lld",ans);
	return 0;
}
