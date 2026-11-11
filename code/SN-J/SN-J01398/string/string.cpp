#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define vec vector
#define pb push_back
int n;
string s="";
vec<char> C;
vec<int> X; 
inline void Solve(){
	cin>>n;
	for(int i=1;i<=n;i++){
		ll x;
		char c;
		cin>>x>>c;
		X.pb(x);
		C.pb(c);
	}
	ll ans=0;
	int l=0,r=n-1;
	while(1){
		if(l==r) break;
		if(C[l]==C[r]){
			if(X[l]==X[r]){
				l++,r--;
				continue;
			}else{
				ll k=X[l]-X[r];
				if(k>0){
					X[l]-=X[r];
					r--;
				}else{
					X[r]-=X[l];
					l++;
				}
			}
		}else{
			ans+=min(X[l],X[r]);
			ll k=X[l]-X[r];
			if(k>0){
				X[l]-=X[r];
				r--;
			}else{
				X[r]-=X[l];
				l++;
			}
		}
//		cout<<ans<<"\n";
//		cout<<l<<" "<<r<<"\n";
	}
	cout<<ans<<"\n";
}
/*
3 
2 a
2 b
1 c

6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
*/
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int _=1;
	//cin>>_;
	while(_--) Solve();
	return 0;
}

