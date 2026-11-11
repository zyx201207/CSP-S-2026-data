#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
const ll inf=0x3f3f3f3f3f3f3f3f;
const int N=2e6+5;
int n;
ll d;
ll a[N];
ll ans[N];
void slove(){
	cin>>n>>d;
	ll cha=0;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		cha=a[i]-a[i-1];
	}
	if(cha==0||2*cha>d||cha>d){
		cout<<0<<'\n';
		return ;
	}
	if(n-3<=0)	cout<<0<<'\n';
	else cout<<n-3<<'\n';
}

int c,t;

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		slove();
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}