// Think TWICE
// Code ONCE
// NEVER FORGET YOUR 143pts IN NOIP 2025
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define up(l,r,i) for(int i=(l);i<=(int)(r);++i)
#define pb emplace_back

void file(string fl){
	freopen((fl+".in").c_str(),"r",stdin);
	freopen((fl+".out").c_str(),"w",stdout);
}

ll ksm(ll a,ll b,ll p){
	ll ret=1%p;
	while(b){
		if(b&1)ret=ret*a%p;
		a=a*a%p;
	}
	return ret;
}

constexpr int N=5e5+7;
constexpr ll INF=1e18;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T=1;
	//cin>>T;
	while(T--){
		system("fc /w subway7.out subway7.ans");
	}
	return 0;
}

