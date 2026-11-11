#include<bits/stdc++.h>
using namespace std;
long long a[500010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	long long m;
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	int l=1,ans=1;
	long long sum=a[1];
	for(int i=2;i<=n;i++){
		sum+=a[i];
		while(l<=i&&1ll*(i-l+1)*a[i]-sum>m){
			sum-=a[l],l++;
		}
		ans=max(ans,i-l+1);
	}
	cout<<ans<<endl;
	return 0;
}

