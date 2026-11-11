#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
ll n,m,t,sum[10001],ans=0;
vector<ll> a;
vector<ll> b;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	for(int i=1;i<=n;++i){
		ll t;
		scanf("%lld",&t);
		a.push_back(t);
	}
	sort(a.begin(),a.end());
	for(int i=0;i<n-1;++i){
		sum[i+1]=a[i+1]-a[i];
		b.push_back(sum[i+1]);
	}
	sort(b.begin(),b.end());
	for(int i=0;i<n-1;++i){
		int temp=m;
		if(temp-b[i]>=0){
			m-=b[i];
			ans++;
		}
	}
	printf("%lld",ans);
	return 0;
}