#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
long long op,t;
long long n;
long long len;
long long a[N];

void solve(){
	cin>>n>>len;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	long long c=a[2]-a[1];
	//cout<<n<<' '<<c<<' '<<len<<'\n';
	if(len>c){
		cout<<n-(len/c)-(len/c)+1<<'\n';
	}else{
		cout<<0<<'\n';
	}
	return;
}

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>op>>t;
	while(t--){
		solve();
	}
	return 0;
}
