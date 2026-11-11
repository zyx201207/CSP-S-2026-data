#include<bits/stdc++.h>
#define int long long
#define pb push_back

using namespace std;

const int N=2e5+5;
int a[N],n,m,ans;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	vector<int> v;
	for(int i=1;i<=n;i++) cin>>a[i],v.pb(a[i]);
	for(int i=31;i>=0;i--){
		vector<int> nv;
		for(int x:v){
			if(x>>i&1) nv.pb(x);
		}
		if(nv.size()>=m){
			ans|=(1<<i);
			v=nv;
		}
	}
	cout<<ans;
}