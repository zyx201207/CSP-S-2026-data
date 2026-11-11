#include<bits/stdc++.h>

using namespace std;

int main(){
	
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	int c,t;
	cin>>c>>t;
	while(t--){
		int n;
		long long d;
		cin>>n>>d;
		vector<long long> x(n+1,0);
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		if(c==0||c==11||c==12){
			int s=x[2]-x[1];
			if(s/d>=2){
				cout<<n-2*s/d+1<<'\n';
			}
			else{
				cout<<0<<'\n';
			}
		}
	}
	
	return 0;
}
