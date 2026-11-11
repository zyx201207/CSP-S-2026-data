#include<bits/stdc++.h>
using namespace std;
int n;
long long m,us,maxans=-1,ans,die=1;
long long a[600100];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++){
		ans++;
		us+=(a[i]-a[i-1])*ans;
		while(us>m){
			us-=a[i]-a[die];
			ans--;
			die++;
		}
		maxans=max(maxans,ans);
	}maxans++;
	printf("%lld",maxans);
	return 0;
}
