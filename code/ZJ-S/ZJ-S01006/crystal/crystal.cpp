#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,ans;
long long m,a[N];
long long sum,t;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+1+n);
	for(int l=1,r=1;r<=n;r++){
		sum+=a[r];
		//[l,r] -> a[r]
		t=a[r]*(r-l+1)-sum;
		if(t<=m) ans=max(ans,r-l+1);
		else sum-=a[l++];
	}
	printf("%d\n",ans);
	return 0;
}