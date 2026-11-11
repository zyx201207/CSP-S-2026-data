#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[2000006];
int n,d;
int c,t;
void solve(){
	cin>>n>>d;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	int cha=a[2]-a[1];
	if(d<cha||d/cha==1){
		cout<<0<<'\n';
		return;
	}
	int an=d/cha;
	if(n-an*2+1<0){
		cout<<0<<'\n';
		return ;
	}
	cout<<n-an*2+1<<'\n';
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		
		solve();
	}
	return 0;
}
