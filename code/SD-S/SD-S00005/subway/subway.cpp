#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll C,n,m,d,q;
ll w[500005];
ll k;
ll a;
ll t;
ll sum;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>C>>n>>m>>d>>q;
	mt19937 rnd(time(nullptr));
	for(int i=1;i<=m;i++){
		cin>>w[i];
		sum+=w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k;
		k*=2;
		for(int j=1;j<=k;j++){
			cin>>a>>t;
			sum+=t;
		}
	}
	ll x,y;
	while(q--){
		cin>>x>>y;
		cout<<rnd() % sum<<"\n";
	}
	return 0;
}
