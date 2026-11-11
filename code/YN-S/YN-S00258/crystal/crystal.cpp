#include<bits/stdc++.h>
using namespace std;
//#define long long long long
long long n,m,ans=1;
const long long maxn=5e5+13;
long long a[maxn],sum[maxn];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		
	}
	sort(a+1,a+n+1);
	for(long long i=1;i<n;i++){
		sum[i]=a[i+1]-a[i];
	}
	/*for(long long i=1;i<n;i++){
		sum[i]=sum[i-1]+sum[i];
	}*/
	long long cnt=0;
	for(long long i=1;i<n;i++){
		cnt+=i*sum[i];
		if(cnt<=m){
			ans++;
		}else{
			cout<<ans;
			return 0;
		}
	}
	return 0;
}
