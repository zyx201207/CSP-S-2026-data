#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+5;
ll a[N],pre[N],l,r,ans;
char c[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,li,ri; scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d%s",&a[i],&c[i]);
	for(int i=1;i<=n;i++) pre[i]=pre[i-1]+a[i];
	li=1,ri=n,l=1,r=pre[n];
	while(l<=r){
		if(l==r||li==ri) break;
		int sl=pre[li]-l+1,sr=r-pre[ri-1];
		if(sl<=sr){
			if(c[li]!=c[ri]) ans+=sl;
			li++,l+=sl,r-=sl;
			if(sl==sr) ri--;
		}
		else{
			if(c[li]!=c[ri]) ans+=sr;
			ri--,l+=sr,r-=sr;
		}
	}
	printf("%lld\n",ans);
	return 0;
}
