#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
void don50000(int &n,vector<ll> &v,ll &m) {
	ll h=0;
	ll r;
	ll ma=1;
	ll mun=1;
	sort (v.begin()+1,v.begin()+n+1);
	for(int i=1; i<=n; ++i) {
		h=0;
		mun=1;
		int j;
		for(j=i-1; j>=1; --j) {
			h+=v[i]-v[j];
			if(h<=m)mun++;
			if(h>m) {
				break;
			}
		}
		ma=max(ma,mun);
	}
	cout<<ma;
}
void doA(int &n,vector<ll> &v,ll &m) {
	ll h=0;
	ll r;
	ll ma=1;
	ll mun=1;
	sort (v.begin()+1,v.begin()+n+1);
	for(int i=1; i<=n; ++i) {
		mun=int(sqrt(2.0*m+0.25)-0.5);

		ma=max(ma,mun+1);
	}
	cout<<ma;
}
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
//	freopen("E:\\新建文件夹\\crystal\\crystal3.in","r",stdin);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	ll m;
	cin>>n>>m;
	unordered_map<ll,ll> ump;
	vector<ll>v(n+10);
	bool A=true,B=true;
	ll ma=INT_MIN;
	
	for(int i=1; i<=n; ++i) {
		cin>>v[i];
		ump[v[i]]++;
		ma=max(ump[v[i]],ma);
		if(v[i]!=i)A=false;
		if(i>=3 && v[i]-v[i-1]!=v[i-1]-v[i-2])B=false;
	}
	if(ump[v[1]]==n) {
		cout<<n;
		return 0;
	}
	if(n==2) {
		if(m>=abs(v[1]-v[2])) {
			cout<<2;
		} else {
			cout<<1;
		}
		return 0;
	}
	if(A) {
		doA(n,v,m);
		return 0;
	}
	if(n<=50000) {
		don50000(n,v,m);
		return 0;
	}
	don50000(n,v,m);
	return 0;
}

