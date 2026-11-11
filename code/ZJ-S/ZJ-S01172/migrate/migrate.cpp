#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=2e6+5;
int c,T;
int n;
ll d,a[N];
ll ans;
bool checka(){
	for(int i=2;i<=n;i++){
		if(a[i]-a[i-1]!=a[2]-a[1]) return false;
	}
	return true;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>c>>T;
	while(T--){
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>a[i];
		ans=0;
		if(checka()){
			int k=1;
			for(int i=1;i<=n&&a[i]-a[1]<=d;i++) k=i;
			k--;
			if(k>1) ans=max(0,n-(2*k-1));
		}
		cout<<ans<<'\n';
	}
	return 0;
}