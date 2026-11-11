#include <bits/stdc++.h>
using namespace std;

long long n,t1,t2,o,ans;
char c[200010];
long long a[200010];

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1; i<=n; i++){
		scanf("%lld %c",&a[i],&c[i]);
	}
	t1=1,t2=n;
	while(t1!=t2){
		o=min(a[t1],a[t2]);
		if(c[t1]!=c[t2]) ans+=o; 
		a[t1]-=o;
		a[t2]-=o;
		if(a[t1]==0) t1++;
		if(a[t2]==0) t2--; 
	}
	printf("%lld\n",ans);
	
	return 0;
}
