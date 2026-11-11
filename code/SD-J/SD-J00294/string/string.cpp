#include<bits/stdc++.h>
#define ll long long
#define int long long 
using namespace std;
ll x,y,n,m,cnt;
char q;
vector<char> s,a;
struct ct{
	ll a,b,l,r;
};
//ct a[200005];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(ll j=1;j<=n;j++){
		cin>>x>>q;
		for(ll i=m;i<=m+x-1;i++){
			s.push_back(q);
			a.push_back(q);
		}
		m+=x;
	}
	reverse(s.begin(),s.end());
	for(ll i=0;i<ceil(m/2.0);i++){
		if(s[i]!=a[i]) cnt++;
	}
    cout<<cnt;
	return 0;
}
