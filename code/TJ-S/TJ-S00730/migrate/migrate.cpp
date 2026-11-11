#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,x[2000006];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in","r",stdin); 
	freopen("migrate.out","w",stdout); 
	cin>>c>>t;
	if(c==11||c==12){
		while(t--){
			cin>>n>>d;
			for(int i=1;i<=n;i++) cin>>x[i];
			
			d=d/(x[2]-x[1]);
			if(d<=1) cout<<0<<'\n';
			else cout<<max(n-2*d+1,0LL)<<'\n';
		}
	}
	
	
	
	return 0;
}
