#include<bits/stdc++.h>
#define AK return 0
using namespace std;
using ll=long long;
static ll qpow(ll x,ll k,ll mod){
	ll res=1;
	while(k){
		if(k&1)res=res*x%mod;
		x=x*x%mod;
		k>>=1;
	}
	return res;
}
static ll qpow(ll x,ll k){
	ll res=1;
	while(k){
		if(k&1)res=res*x;
		x=x*x;
		k>>=1;
	}
	return res;
}
ll num_sum(string x){
	ll cnt=0;
	for(ll i=0;i<x.size();i++){
		if('0'<=x[i]&&x[i]<='9'){
			cnt=cnt+x[i]-48;
		}
	}
	return cnt;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
	ll c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	string a,b,cc;
	getline(cin,a);
	getline(cin,b);
	getline(cin,cc);
	ll aa=num_sum(a),bb=num_sum(b),ccc=num_sum(cc);
	vector<ll>e(3);
	e[0]=aa;e[1]=bb;e[2]=ccc;
	sort(e.begin(),e.end());
	cout<<e[2]<<"\n"<<e[1];
	AK;
}
/*
28,21				32,17
36,21				35 16
1180,139
4151,36
168500,288
4322142,14502
19425664,53906
*/