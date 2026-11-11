#include<bits/stdc++.h>
using namespace std;
//#define long long long long
long long c,n,m,d,p;
const long long maxn=5e2+13;
long long a[maxn];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(a,0,sizeof(a));
	cin>>c>>n>>m>>d>>p;
	for(long long i=1;i<=m;i++){
		cin>>a[i];
	}
	long long x[m+1][m+1];
	memset(x,0,sizeof(x));
	for(long long i=1;i<=n;i++){
		long long k;
		cin>>k;
		for(long long j=1;j<=k;j++){
			long long b,cc;
			cin>>b>>cc;
			x[i][2]=max(x[i][2],cc);
			//cin>>x[k]
		}
	}
	while(p--){
		long long st,en;
		cin>>st>>en;
		long long ans=0;
		for(long long i=st;i<=en;i++){
			ans+=x[c][2]+a[i];
		}
		cout<<ans*2+ans/4+(ans%2==0?1:ans+1)<<"\n";
	}
	return 0;
}
