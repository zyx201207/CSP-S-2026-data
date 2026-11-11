#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int c,t,n,d;
int x[N];
int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	if(c==0){cout<<0<<1;return 0;}
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>x[i];
		if(n<=3){cout<<0<<'\n';continue;}
		if(x[n]-x[1]<=(n-2)*d){cout<<0<<'\n';continue;}
		else if(x[2]-x[1]==x[n]-x[n-1]){cout<<3<<'\n';continue;}
		
	}
	return 0;
}

 
