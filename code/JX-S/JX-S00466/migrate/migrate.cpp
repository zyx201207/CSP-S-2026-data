#include<bits/stdc++.h>
using namespace std;
void solve(){
	long long n,d;
	cin>>n>>d;
	vector<long long> a(n);
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	long long ans=0;
	for(int i=0;i<n;i++){
		long long r1=upper_bound(a.begin(),a.end(),a[i]+d)-a.begin()-1;
		if(r1<i+2) continue;
		long long low=a[r1-2]+d,high=a[r1-1]+d;
		long long vs=upper_bound(a.begin(),a.end(),low)-a.begin();
		long long ve=upper_bound(a.begin(),a.end(),high)-a.begin();
		vs=max(vs,r1+1);
		if(vs<ve) ans+=(ve-vs);
	}
	cout<<ans<<endl;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	long long c,t;
	if(cin>>c>>t){
		while(t--) solve();
	}
	return 0;
}
