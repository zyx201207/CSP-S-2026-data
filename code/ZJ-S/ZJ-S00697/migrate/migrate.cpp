#include<bits/stdc++.h>
#define ll long long
#define N 2000010
using namespace std;
int c,t;
int n;
ll x[N],d;
ll a,ans;
bool flag=1;
void solve(){
	if(d<a){
		cout<<"0\n";
		return ;
	}
	ll b=d/a;
	if(n<2*b||b==1) cout<<"0\n";
	else cout<<n-2*b+1<<'\n';
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		ans=0;
		cin>>n>>d;
		cin>>x[1]>>x[2];
		a=x[2]-x[1];
		for(int i=3;i<=n;i++) cin>>x[i];
		if(flag) solve();
//		for(int i=1,j=1,k=1;i<=n;i++){
//			while(x[j]-x[i]<=d&&j<=n) j++;
//			j--;
//			if(j>n) break;
//			if(j+1<=n) ans++;
//		}
//		cout<<ans<<'\n';
	}
	return 0;
}
