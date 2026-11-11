#include <bits/stdc++.h>
using namespace std;

long long xy[2000006];
void solve(){
	bool A=1;
	long long n,d;
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>xy[i];
	}
	for(int i=2;i<n;i++){
		if(xy[i]-xy[i-1]!=xy[i+1]-xy[i])A=0;
	}
	if(A){
		long long r=xy[2]-xy[1];
		long long ans=d/r;
		if(ans<0)cout<<0<<"\n";
		else cout<<ans<<"\n";
		
	}
	
	
	
}



int main(){
	
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	int c,t;
	cin>>c>>t;
	while(t--){
		solve();
	}
	
}
