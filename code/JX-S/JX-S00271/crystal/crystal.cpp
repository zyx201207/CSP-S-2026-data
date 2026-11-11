#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

// feature B & A

int n;
ll m,in,d;
vector<ll> v;

int main(){

	// freopen("t1.in","r+",stdin);

	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);

	cin>>n>>m;
	for(int _=0;_<n;++_){
		cin>>in;
		v.push_back(in);
	}

	sort(v.begin(),v.end());

	d=v[1]-v[0];

	ll res=1;

	// cout<<m<<"\n\n";

	for(int i=1;m>=i*d;++i){
		m-=i*d;
		res++;

		// cout<<m<<";"<<res<<"\n\n";
	}

	cout<<res<<'\n';

	return 0;
}