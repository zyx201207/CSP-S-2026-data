#include<bits/stdc++.h>
using namespace std;
int c,t,n,d;
const int N=2e6+10;
int x[N];
int dist(int u,int v){
	int now=u,d=0;
	if(x[u]>x[v]) swap(u,v);
	while(now<v){
		nnow=upper_bound(x+1,x+n+1,x[u]+d)-x-1;
		d++;
		if(nnow==now) return -1;
		now=nnow;
	}
	return d;
}
int isd(int u,int v){
	for(int i=u;i<=v-2;i++){
		if(x[i+2]-x[i]<d*2) return true;
	}
}
int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>x[i];
		sort(x+1,x+n+1);
	}
	return 0;
}