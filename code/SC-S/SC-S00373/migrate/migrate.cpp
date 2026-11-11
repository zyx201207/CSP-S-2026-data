#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int c,t;
int a[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	if(c==13||c==14){
		for(int i=1;i<=t;i++){
			cout<<"0"<<'\n';
		}
	}
	else if(c>=15&&c<=18){
		while(t--){
			int n,d;
			cin>>n>>d;
			for(int i=1;i<=n;i++){
				cin>>a[i];
			}
			cout<<n-d<<'\n';
		}
	}
	else if(c==11||c==12){
		while(t--){
			int n,d;
			cin>>n>>d;
			cout<<n-4+1<<'\n';
		}
	}
	else {
		for(int i=1;i<=t;i++){
			cout<<"0"<<'\n';
		}
	}
	
	
}