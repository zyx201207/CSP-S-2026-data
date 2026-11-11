#include<bits/stdc++.h>
using namespace std;
int n,d;
long long a[2000005];
bool dc=1;
void solve(){
	cin>>n>>d;
	if(n<=3){
		cout<<0<<'\n';
		return ;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i>2&&a[i]-a[i-1]!=a[i-1]-a[i-2])dc=0;
	}
	if(dc){
		if((a[2]-a[1])>d){cout<<0<<'\n';return ;};
		cout<<n*(n-1)/2-2*n+3<<'\n';
	}
	if(n>5000){
		long long ans=0;
		int r=1;
		for(int i=1;i<=n;i++){
			while(a[r]-a[i]<=d)r++;
			ans+=n-r+1;
		}
		cout<<ans<<'\n';
		return ;
	}else cout<<0<<'\n';
	
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--)solve();
	return 0;
}
