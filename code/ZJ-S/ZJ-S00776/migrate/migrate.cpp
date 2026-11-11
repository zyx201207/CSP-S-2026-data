#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int c,t;
int x[100005];
void solve(){
	int n,d,ans=0;
	cin>>n>>d;
	if(n>100000){
		cout<<0<<'\n';
		return;
	}
	for(int i=1;i<=n;i++){
		cin>>x[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i+3;j<=n;j++){
			if(x[j]-x[i]<=d) continue;
			if(x[j]-x[i]>d&&x[j]-x[i]<d*2){
				ans++;
			}
		}
	}
	cout<<ans<<'\n';
	return;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		solve();
	}
	return 0;
}
