#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int N=2e6+25;
int a[N];
int n,d;
bool check(int x){
	if(abs(a[x]-a[x-1])==abs(a[x-1]-a[x-2])&&abs(a[x-1]-a[x-2])==abs(a[x-2]-a[x-3])&&abs(a[x-2]-a[x-3])<=d){
		return 1;
	} 
	return 0;
}
void solve(){
	cin>>n>>d;
	bool f=1,f2=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int sum=0;
	for(int i=4;i<=n;i++){
		if(check(i)){
			sum++;
		}
	}
	cout<<sum<<endl;
	return ;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int RP,T=1;
	cin>>RP>>T;
	while(T--){
		solve();
	}
	return 0;
}
