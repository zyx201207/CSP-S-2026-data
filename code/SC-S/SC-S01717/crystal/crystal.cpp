#include <bits/stdc++.h>
#define int long long
using namespace std;
int rd(){
	int w = 0 , f = 1;char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f = -1;
		ch=getchar();
	}
	while('0'<=ch&&ch<='9') w=(w<<3)+(w<<1)+(ch&15),ch=getchar();
	return w*f;
}
const int N = 5e5+15;
int n,m,a[N],s[N],ans;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=rd(),m=rd();
	for(int i = 1 ; i<=n ; i++) a[i]=rd();
	sort(a+1,a+n+1);
	for(int i = 1 ; i<=n ; i++) s[i]=s[i-1]+a[i];
	for(int i = 1 , j = 1 ; i<=n ; i++){
		while(a[i]*(i-j+1)-(s[i]-s[j-1])>m) ++j;
		ans=max(ans,i-j+1);
	}
	printf("%lld",ans);
	return 0;
}