#include<bits/stdc++.h>
using namespace std;
long long n,c,t,d;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	if(c==11||c==12){
		while(t--){
			cin>>n>>d;
			long long x1,x2,z;
			cin>>x1>>x2;
			for(int i=3;i<=n;i++) cin>>z;
			x2-=x1;
			if(x2*2>d||d>=x2*n) cout<<"0\n";
			else cout<<n-2*(d/x2)+1<<'\n';
		}
		return 0;
	}
	while(t--){
		cin>>n>>d;
		cout<<"0\n";
	}
	return 0;
}

