#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,x[2000010];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>x[i];
		if(n<=3){
			cout<<"0\n";
			continue;
		}
		if(x[1]==x[2]){
			cout<<"0\n";
			continue;
		}
		d/=(x[2]-x[1]);
		if(d>=3){
			cout<<"0\n";
			continue;
		}
		if(d==1){
			cout<<"0\n";
			continue;
		}
		cout<<n-3<<"\n";
	}
}