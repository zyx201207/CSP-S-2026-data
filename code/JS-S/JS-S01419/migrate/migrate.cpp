#include<bits/stdc++.h>
using namespace std;
long long x[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	long long c,t;cin>>c>>t;
	while(t--){
		long long n,d;cin>>n>>d;
		for(long long i=1;i<=n;i++){
		cin>>x[i];	
		}
		sort(x+1,x+n+1);
		if(c==11||c==12){
			long long ans=0;
			long long len=abs(x[n]-x[n-1]);
			for(long long i=1;i<=n;i++){
					if(d>=2*len&&i+2<=n)ans++;
			}
			cout<<ans;
			cout<<"\n";
		}else if(c==13||c==14){
			long long ans=0;
			for(long long i=1;i<=n;i++){
					if(i+1<=n&&abs(x[i+1]-x[i])<=d)ans++;
			}
			cout<<ans;
			cout<<"\n";
		}else
			cout<<0<<"\n";
		
		
	}
}
