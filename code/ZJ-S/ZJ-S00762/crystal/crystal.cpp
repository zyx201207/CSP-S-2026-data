#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll m;
ll a[500005],s[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	int t1=0,t2=1,ans=0;ll p=0;
	//for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
	while(t1<=t2&&t1<n){
		t1++;p-=a[t2]-a[t1];
		while(t2<n&&p+(t2-t1+1)*(a[t2+1]-a[t2])<=m){
			p+=(t2-t1+1)*(a[t2+1]-a[t2]);
			t2++;
			ans=max(ans,t2-t1+1);
		}
	}
	printf("%d",ans);
	return 0;
} 
