#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=5e5+5;
LL a[N],m,s[N];
int n;
bool check(int x){
	LL sum=0x3f3f3f3f3f3f3f3f;
	for(int i=x;i<=n;i++){
		if(x%2==0) sum=min(sum,s[i]-s[(i-x+i+2)/2-1]*2+s[i-x]);
		else sum=min(sum,s[i]-s[(i-x+1+i)/2-1]*2+s[i-x]);
	}
	if(sum>m) return false;
	return true;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		s[i]=s[i-1]+a[i];
	}
	sort(a+1,a+n+1);
	int l=1,r=n,ans=0;
	while(l<=r){
		int mid=(l+r)>>1;
		if(check(mid)){
			ans=mid;
			l=mid+1;
		}
		else r=mid-1;
	}
	printf("%d",ans);
	return 0;
}
