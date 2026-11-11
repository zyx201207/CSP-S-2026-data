#include<bits/stdc++.h>
using namespace std;
long long n,x[2000005],c2,t,d.c[2000005],sc[2000005];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c2>>t;
	while(t--){
		cin>>n>>d;
		bool f=1;
		for(int i=1;i<=n;i++){
			cin>>x[i];
			if((x[i]-x[i-1])!=(x[i+1]-x[i]) && i!=1 && i!=n){
				f=0;
			}
		}
		if(f){
			cout<<n-3<<'\n';
			continue;
		}
		else{
			cout<<0<<'\n';
			continue;
		}
	}
	
	
	return 0;
}