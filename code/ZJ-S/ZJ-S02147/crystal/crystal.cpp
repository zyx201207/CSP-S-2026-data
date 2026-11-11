#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+5;
int n;
ll m;
ll a[N];
ll pr[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		if(a[i]==a[i-1])pr[i]=pr[i-1];
		pr[i]=pr[i-1]+(i-1ll)*(a[i]-a[i-1]);
	}
	int ans=-1,l=0,ns=0;
	for(int i=1;i<=n;i++){
		ns+=(a[i]-a[i-1])*l;
		if(pr[i]-ns<=m)ans=max(ans,i-l);
		else{
			while(pr[i]-ns>m){
				ns+=a[i]-a[++l];
			}
			ans=max(ans,i-l);
		}
		
	}
	printf("%lld",ans);
	return 0;
}