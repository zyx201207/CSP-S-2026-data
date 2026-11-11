#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t,n,d;
int x[2000010];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		int p;
		memset(x,0,sizeof(x));
		for(int i=1;i<=n;i++) cin>>x[i];
		p=x[n]-x[n-1];
		if(d>=2*p){
			d/=p; d*=p;
			if(2*d>=p*(n-1)){
				cout<<0<<endl;
				continue;
			} 
			cout<<n-2*d/p+1<<endl;
		} 
		else cout<<0<<endl;
	}
	return 0;
}
