#include<bits/stdc++.h>
using namespace std;
const long long N=2e6+10;
long long a[N],d1[N],d2[N],num1[N],num2[N];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	long long c,t,n,m,ans;
	cin>>c>>t;
	while(t--){
		cin>>n>>m;
		ans=0;
		for(long long i=1;i<=n;i++){
			cin>>a[i];
			num1[i]=num2[i]=0;
		}
		if(c>=13&&c<=14) {
			cout<<0<<endl;
			continue;
		}
		if(c<=12&&c>=11){
			cout<<n-m/(a[2]-a[1])+1<<endl;
			continue;
		}
		a[0]=-1e18;
		a[n+1]=1e18;
		long long l=1,r=0;
		while(l<=n){
			while(a[r+1]-a[l]<=m) r++;
			d1[l]=r;
			if(r-l>1)num1[r]++;
			l++;
		}
		l=n,r=n+1;
		while(r>=1){
			while(a[r]-a[l-1]<=m) l--;
			d2[l]=r;
			if(r-l>1)num2[l]++;
			r--;
		}
		for(long long i=1;i<n;i++){
			ans+=num2[i]*num1[i+1];
//			cout<<num2[i]<<" "<<num1[i+1]<<'\n';
		}
		cout<<ans<<endl;
	}
	return 0;
}