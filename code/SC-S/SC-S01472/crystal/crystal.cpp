#include<bits/stdc++.h> 
using namespace std;
const int N=5e5+11;
long long n,m;
long long a[N],f[N],ans=0;
bool cmp(long long i,long long j){return i<j;}
void solve(){
	long long j=0;
	for(long long i=1;i<=n;i++){
		while((j<=i)&&((f[i]-f[j]-((j-1)*(a[i]-a[j])))>m)){
			j++;
		}
		if((f[i]-f[j]-((j-1)*(a[i]-a[j])))<=m){
			long long tmp=i-j+1;
			ans=max(ans,tmp);
		}
	}
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	long long ts=0;
	for(long long i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}	
	sort(a+1,a+n+1,cmp);
	for(long long i=1;i<=n;i++){
		f[i]=a[i]*(i-1)-ts;
		ts+=a[i];
	}
	solve();
	printf("%lld",ans);
	return 0;
}