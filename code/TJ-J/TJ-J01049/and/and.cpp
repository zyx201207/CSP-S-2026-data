#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
ll n,m,tmp;ll v[200010];
ll dfs(ll nw,ll p,ll gt){
	if(p>n) {return -1;}
	if(gt>m){return -1;}
	if(n-p<m-gt){return -1;}
	if(p==n){return nw;}
	if(gt==m) {return nw;}
	//cout<<nw<<' '<<v[p]<<' '<<p+1<<' '<<gt<<' '<<(nw&v[p])<<'\n';
	return max(dfs(nw,p+1,gt),dfs((nw&v[p]),p+1,gt+1));
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(ll i=0;i<n;i++){
		cin>>tmp;v[i]=tmp;
	}
	ll M=1;
	for(ll i=1;i<=31;i++){
		M*=2;
	}
	cout<<dfs(M-1,0,0);
	return 0;
}
