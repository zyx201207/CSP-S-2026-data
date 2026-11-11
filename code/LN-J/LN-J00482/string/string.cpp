#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5;
ll len,ans;
int n,a[N];
char c[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d\n",&n);
	for(int i=1;i<=n;i++){
		scanf("%d %c\n",&a[i],&c[i]);
		len+=1ll*a[i];
	}
	int i=1,j=n;
	while(i<j){
		if(c[i]!=c[j])++ans;
		--a[i];--a[j];
		if(!a[i])++i;
		if(!a[j])--j;
	}
	printf("%lld",ans);
	return 0;
}
