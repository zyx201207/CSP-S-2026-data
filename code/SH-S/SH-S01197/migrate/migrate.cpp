#include<bits/stdc++.h>
//#define int long long
using namespace std;

const int Max_N=2000000+10;
int c,T;
int n,d;
int x[Max_N], lx[Max_N], rx[Max_N], llx[Max_N], lrx[Max_N], rlx[Max_N] ,rrx[Max_N];

void init(int u,int c){
	int l = 1, r = u;
	while(l < r){
		int mid = (l + r) >> 1;
		if(x[mid] + c > x[u]) r = mid;
		else l = mid+1;
	}
	
	lx[u] = l;
	int l = u, r = n;
	while(l < r){
		int mid = (l + r) >> 1;
		if(x[mid] - c < x[u]) l = mid;
		else r = mid - 1;
	}
	rx[u] = l;
}

void solve(){
	memset(subs, 0, sizeof(subs));
	
	cin >> n >> d;
	
	for(int i = 1; i <= n; i++) cin>>x[i];
	for(int i = 1; i <= n; i++) init(i, d);
	
	for(int i = 1; i <= n; i++){
	} 
	
}

signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	cin>>c>>T;
//	T=1;
	
	while(T--){
		solve();	
	}
}
