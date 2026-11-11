#include<bits/stdc++.h>
using namespace std;
long long n,m,ans=1,t;
long long a[500005];
long long z;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+1+n);
	t=m;
	for(int i=n;i>=1;i--){
		if((i-ans)<1){
			break;
		}
		while((t-(a[i]-a[i-ans]))>=0&&(i-ans)>=1){
			t-=(a[i]-a[i-ans]);
			ans++;
		}
		z=max(z,ans);
		t+=(a[i]-a[i-1]);
		ans--;
	}
	cout<<z;
	return 0;
}
