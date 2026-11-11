#include<bits/stdc++.h> 
using namespace std;
long long n,c,d,t,x1,x2,x3,k,x4;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		cin>>x1>>x2;
		for(int i=1;i<=n-2;i++) cin>>x3;
		k=max(x1-x2,x2-x1);
		if(d<=k) cout<<0<<'\n';
		else{
			x3=d/k;
			x4=x3*2;
			if(n-x4+1<=0) cout<<0<<'\n';
			else cout<<n-x4+1<<'\n';
		}
	}
	return 0;
}
