#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
pair<ll,char> p[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(ll i=0;i<n;i++){
		ll a;char c;
		cin>>a;
	
		cin>>c;
		p[i].first=a;
		p[i].second=c;
		//cout<<p[i].first<<" "<<p[i].second<<endl;
	}
	ll r=n-1,l=0;
	ll c=0;
	while(l<r){
		if(p[l].first>p[r].first){
			p[l].first-=p[r].first;
			if(p[l].second!=p[r].second)
				c+=p[r].first;
			r--;
		}
		if(p[l].first<p[r].first){
			p[r].first-=p[l].first;
			if(p[l].second!=p[r].second)
				c+=p[l].first;
			l++;
		}
		if(p[l].first==p[r].first){
			if(p[l].second!=p[r].second)
				c+=p[r].first;
			r--;l++;
		}
	}
	cout<<c;
	return 0;
}
