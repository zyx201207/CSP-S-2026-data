#include<bits/stdc++.h>
using namespace std;
const long long M=2e5+10;
long long n,m,ans;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%lld %lld\n",&n,&m);
	vector<long long> a;
	vector<long long> b;
	for(long long i=0;i<n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a.begin(),a.end());
	for(long long j=0;j<m;j++){
		b[j]=a[n-j];
	}
	for(long long j=0;j<m;j++){
		ans=b[0];
		ans&=b[j];
	}
	printf("%lld",ans);
	return 0;
}