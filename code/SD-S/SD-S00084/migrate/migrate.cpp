#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define pii pair<int,int>
#define fi first
#define se second
#define lowbit(x) x&(-x)
#define fst ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

const int N=2e6+10;//注意修改
ll c,T,n,l;
ll x[N];
void solve(){
	cin>>n>>l;
	for(int i=1;i<=n;i++) cin>>x[i];
	if(c==11||c==12){
		ll d=x[2]-x[1];
		ll p=floor(1.0*(l/d));//最多跨越几个格子 
	//	cout<<p<<' ';
		if(p<=1) {
			cout<<0<<endl;
			return ;
		}else{
			cout<<max(0ll,n-(2*p-1))<<endl;
		}
	}else{
		cout<<0<<endl;
	}
	
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	fst
	cin>>c>>T;
	while(T--){
		solve();
	}
	return 0;
}



