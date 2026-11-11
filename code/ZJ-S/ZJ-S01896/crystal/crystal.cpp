#include <bits/stdc++.h>
using namespace std;
long long n,m,a[500005],h[500005],q[500005],ans=0;

/*long long erf(long long d){
	long long l=1,r=d;
	cout<<d<<"\n";
	while(l<r){
		long long mid=(l+r)/2;
		if(a[d]*(d-mid+1)-(h[d]-h[l-1])<=m) r=mid;
		else l=mid+1;
		cout<<l<<' '<<r<<' '<<mid<<"\n";
	}
	cout<<"\n";
	return d-l+1;
}*/

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	//for(long long i=0;i<n;i++) cout<<a[i]<<' ';
	for(long long i=1;i<=n;i++) h[i]=h[i-1]+a[i];
	//for(long long i=0;i<=n;i++) cout<<h[i]<<' ';
	
	for(long long i=1;i<=n;i++){
		long long l=1,r=i;
		//cout<<i<<' '<<a[i]<<"\n";
		while(l<=r){
			long long mid=(l+r)/2;
			//cout<<l<<' '<<r<<' '<<mid<<' '<<a[i]*(i-mid+1)<<' '<<h[i]<<' '<<h[mid-1]<<' '<<(h[i]-h[mid-1])<<' '<<a[i]*(i-mid+1)-(h[i]-h[mid-1])<<"\n";
			if(a[i]*(i-mid+1)-(h[i]-h[mid-1])<=m) r=mid-1;
			else l=mid+1;
		}
		q[i]=i-l+1;
		//cout<<l<<' '<<q[i]<<"\n"<<"\n";
	}
	//for(long long i=0;i<=n;i++) cout<<q[i]<<' ';
	for(long long i=1;i<=n;i++) ans=max(ans,q[i]);
	cout<<ans;
	return 0;
} 
