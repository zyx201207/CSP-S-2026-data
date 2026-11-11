#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=	2e6+5;
int c,t;
int n,m;
int a[maxn];
void solve(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m%2==1){
		cout<<0<<'\n';
	}else{
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(a[i+1]==a[i]+m/2 && a[i+2] ==a[i]+m && a[i+3]==a[i]+3*m/2) ++cnt; 
		}
		cout<<cnt<<'\n';
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		solve();
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
