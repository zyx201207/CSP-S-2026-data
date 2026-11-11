#include<bits/stdc++.h>
using namespace std;
int n,ans,l;
long long m,a[500005],cs;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	ans=1;l=1;cs=0;
	for(int i=2;i<=n;i++){
		cs+=(a[i]-a[i-1])*(i-l);
		while(cs>m){
			cs-=a[i]-a[l];
			l++;
		}
		ans=max(ans,i-l+1);
	}
	printf("%d\n",ans);
	return 0;
}