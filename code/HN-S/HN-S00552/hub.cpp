#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;

int c,T;
int n,k;
int u[N],v[N];

void solve(){
	cin>>n>>k;
	for (int i=1;i<=n-1;i++){
		cin>>u[i]>>v[i];
	}
	if (n%2!=0){
		cout<<1<<"\n";
	}
	else{
		cout<<2<<"\n";
	}
} 

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>T;
	while (T--){
		solve();
	}
	return 0;
}
