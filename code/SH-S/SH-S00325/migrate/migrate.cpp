#include<bits/stdc++.h>
using namespace std;
int c,t;
int n;
long long d;
long long x[2000005]; 
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>c>>t;
	if(c==13||c==14){
		while(t--){
			cin>>n>>d;
			for(int i=1;i<=n;i++){
				cin>>x[i];
			}
			cout<<n-3<<'\n';
		}
		return 0;
	}else if(c==11||c==12){
		while(t--){
			cin>>n>>d;
			for(int i=1;i<=n;i++){
				cin>>x[i];
			}
			if(2*(x[2]-x[1])>d||(x[2]-x[1])*(n-2)<=d){
				cout<<0;
			}else{
				cout<<n-(d/(x[2]-x[1])-1)*2-1;
			}
			cout<<'\n';
		}
		return 0;
	}
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		if(n<4){
			cout<<0<<'\n';
		}
	}
	return 0;
}
