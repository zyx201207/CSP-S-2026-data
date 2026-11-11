#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=2000006;
ll n,d,s,cnt,b1,ans,res,x[N];
void solvecha(){
	if(d<2*b1){
		cout<<0<<endl;
		return;
	}
	ll mx=d/b1;
	cout<<max(0ll,n-mx*2+1)<<endl;
}
void dfs(ll st,ll fi,ll ti){
	if(st==fi){
		if(ti==0)
			ans++;
		return;
	}
	if(ti==0){
		if(st==fi)
			ans++;
		return;
	}
	if(x[st]+d<x[st+1])
		return;
	s=upper_bound(x+st,x+fi+1,x[st]+d)-x;
	s--;
	for(ll i=st+1;i<=s;i++){
		dfs(i,fi,ti-1);
	}
}
void solve(){
	x[n+1]=3e18+1;
	for(ll i=1;i<n;i++){
		for(ll j=i+1;j<=n;j++){
			s=i,cnt=0;
			bool b=0;
			while(s<j){
				if(x[s]+d>=x[j]){
					cnt++;
					break;
				}
				if(x[s]+d<x[s+1]){
					b=1;
					break;
				}
				s=upper_bound(x+s,x+j+1,x[s]+d)-x;
				s--;
				cnt++;
			}
			if(cnt==1)
				continue;
			if(b==1)
				break;
			dfs(i,j,cnt);
			if(ans==2)
				res++;
			ans=0;
		}
	}
	cout<<res<<endl;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ll c,t;
	cin>>c>>t;
	for(ll i=1;i<=t;i++){
		cin>>n>>d;
		cin>>x[1]>>x[2];
		b1=x[2]-x[1];
		for(ll j=3;j<=n;j++){
			cin>>x[j];
			if(x[j]-x[j-1]!=b1)
				b1=0;
		}
		if(n<=3){
			cout<<0<<endl;
			continue;
		}
		if(b1!=0){
			solvecha();
		}
		else{
			solve();
		}
	}
	return 0;
} 
