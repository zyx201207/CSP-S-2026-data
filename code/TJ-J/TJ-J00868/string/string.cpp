#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ll n,sum=0;
	cin>>n;
	vector<pair<ll,char> >v(n+1);
	for(int i=1; i<=n; i++) {
		cin>>v[i].first>>v[i].second;
		sum+=v[i].first;

	}

	ll ans=0;
	ll anslr=sum/2;
	ll cnt=0,f=0;
	vector<pair<ll,char> >l;
	vector<pair<ll,char> >r;
	int i=1;
	for(; i<=n; i++) {
		ll val=v[i].first;
		if(cnt+val>anslr) {
			ll abc=cnt+val-anslr-(sum & 1?1:0);
			ll aaa=val-abc-(sum & 1?1:0);
			l.push_back({aaa,v[i].second});
			r.push_back({abc,v[i].second});
			break;
		}
		cnt+=val;
		l.push_back({val,v[i].second});
	}
	i++;
	for(; i<=n; i++) {
		ll val=v[i].first;
		r.push_back({val,v[i].second});
	}
	reverse(l.begin(),l.end());
	ll o=0;
	for(int i=0; i<r.size(); i++) {
		ll val=r[i].first;
		for(;o<l.size(); o++) {
			ll j=o;
			ll va=l[j].first;
			ll flag=(l[j].second==r[i].second ? 0:1);
			if(val>=va){
				val-=va;
				ans+=va*flag;
			}
			else {
				ans+=val*flag;
				l[j].first-=val;
				break;
			}
		}
	}
	cout<<ans;

	fclose(stdin);
	fclose(stdout);
	return 0;
}
