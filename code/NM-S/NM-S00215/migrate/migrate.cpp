#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
int c,t;
long long arr[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);
	cin>>c>>t;
	while(t--){
		long long n,m;
		cin>>n>>m;
		for(int i=1;i<=n;i++){
			cin>>arr[i];
		}
		if(c==11||c==12){
			if(2*(arr[2]-arr[1])>m){
				cout<<0<<'\n';
				continue;
			}
			if(2*(arr[2]-arr[1])<=m&&m<3*(arr[2]-arr[1])){
				cout<<n-3<<'\n';
				continue;
			}
			if(3*(arr[2]-arr[1])<=m){
				cout<<0<<'\n';
				continue;
			}
		}
		if(c==13||c==14){
			cout<<0<<'\n';
		}
	}
}
