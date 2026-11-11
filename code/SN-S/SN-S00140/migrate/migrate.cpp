#include<bits/stdc++.h>
using namespace std;
long long a[2000005],y[5005][5005],n,d,ans,sum,cnt,c,t,x[5005][5005];
vector<long long>v[2000005];
int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld %lld",&c,&t);
	while(1) {
		ans=0,t--,sum=0,cnt=0;
		scanf("%lld %lld",&n,&d);
		for(int i=0; i<n; i++) {
			scanf("%lld",&a[i]);
		}
		sum=a[1]-a[0];
		d/=sum;
		ans=(n-d-d+1);
		if(d-1<=0||(n-d-d+1)<=0)ans=0;
		cout<<ans<<endl;
		if(!t)return 0;
	}
}
