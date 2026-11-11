#include <bits/stdc++.h>
using namespace std;


const long long N=500005;
bool cmp(long long u,long long v){
	return u<v;
}
long long ans;
long long f[N];
long long a[N];
int main(){
//	freopen("crystal4.in","r",stdin);
//	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	for(long long i=1;i<=n;i++){
		f[i]=f[i-1]+(__int128)(a[i]-a[i-1])*(i-1);
	}
	if(f[n]<=m){
		cout<<n<<endl;
		return 0;
	}
//	for(long long i=1;i<=n;i++){
//		cout<<f[i]<<" ";
//	}
//	cout<<endl;
	for(long long i=1;i<=n;i++){
		long long u=f[i];
		long long v=upper_bound(f+1,f+n+1,u+m)-f-u-1;
		ans=max(ans,v);
	}
	cout<<ans<<endl;
}
