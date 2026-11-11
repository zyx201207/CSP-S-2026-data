#include<bits/stdc++.h>
using namespace std;
const int mx=1e6+9;
long long c,t,p[mx];
void solve(){
	long long n,d;
	cin>>n>>d;
	for(int i=0;i<n;i++){
		cin>>p[i];
	}
	//clog<<d<<" "<<(p[1]-p[0])<<" "<<n<<"\n";
	if(d<2*(p[1]-p[0])||n==1){
		cout<<"0\n";
		//clog<<">";
	}else{
		cout<<max(0ll,n-2*(d/(p[1]-p[0]))+1)<<"\n";
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>t;
	while(t--){
		solve();
	}
	return 0;
}//Liu Boyan
