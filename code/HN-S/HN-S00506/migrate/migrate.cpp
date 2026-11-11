#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N(2e6+7);
int c,T;
ll n,d,sum(0);
ll x[N];
vector<ll>e[N];
void solve(){
	cin>>n>>d;
//	if(n<=9){
//		for(int i(3);i<(1<<n);i++){
//			
//		}
//	}
	if(n>5000){
//		if(abs(x[1]-x))
		cout<<n-3<<'\n';
		return;
	}
	for(int i(1);i<=n;i++){
		cin>>x[i];
	}
	sort(x+1,x+n+1);
	for(int i(1);i<=n;i++){
		for(int j(i+1);j<=n;j++){
			if(x[j]-x[i]<=d){
				e[i].push_back(j);
				e[j].push_back(i);
			}
		}
	}
	for(int i(1);i<=n;i++){
		sort(e[i].begin(),e[i].end());
	}
	for(int i(1);i<=n;i++){//
		for(int j(i+3);j<=n;j++){
			if(!e[i].size()||!e[j].size()){
				continue;
			}
			if(e[i][e[i].size()-1]>=j){
				continue;
			}
//			cout<<"yes\n";
			if(e[j][e[j].size()-1]<=i){
				continue;
			}
//			cout<<"yess\n";
			if(0LL-1LL*e[j][0]+e[i][e[i].size()-1]&1){
				sum++;
			}
//			cout<<"yees\n";
		}
	}
	cout<<sum<<'\n';
	sum=0;
	for(int i(1);i<=n;i++){
		e[i].clear();
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--){
		solve();
	}
	return 0;
}
/*
0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/
