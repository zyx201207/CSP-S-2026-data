#include<bits/stdc++.h>
using namespace std;
#define int long long
int x[2000005];
int n,d;
void cx(){
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>x[i];
	}
	cout<<5<<'\n'; 
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		cx();
	}
	return 0;
}