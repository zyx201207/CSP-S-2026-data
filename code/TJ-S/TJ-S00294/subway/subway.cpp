#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
const ll M=5e5+99;
ll w[M];
ll a[M];
ll t[M];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	ll k;
	cin>>k;
	for(int i=1;i<=k;i++){
		cin>>a[i]>>t[i];	
	}
	while(q--){
		ll s,e;
		cin>>s>>e;
		ll res=w[s]+w[e];
		for(int i=1;i<=k;i++){
			if(s<=a[i]&&a[i]<=e){
				res+=t[i];
			}
		}
		cout<<res<<endl;
	}
	return 0;
} 
