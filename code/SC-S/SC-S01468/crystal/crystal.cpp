#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n,m,ans=0;
	cin>>n>>m;
	unordered_map<ll,int> p;
	queue<ll> q;
	set<ll,greater<ll>> s;
	vector<ll> v(n+3);
	for(int i=1;i<=n;i++) cin>>v[i];
	sort(v.begin()+1,v.begin()+n+1);
	for(ll i=1,j=1,cnt=0,pre_max;i<=n;i++){
		ll a=v[i];
		if(!p.count(a)) p[a]=1;
		else p[a]++;
		s.insert(a),q.push(a);
		if(i==1) {pre_max=a; continue;}
		if(a>pre_max) cnt+=(i-j)*(a-pre_max),pre_max=a;
		else if(a<pre_max) cnt+=(pre_max-a);
		while(cnt>m){
			ll tail=q.front();
			q.pop(),cnt-=(pre_max-tail),j++;
			p[tail]--;
			if(p[tail]==0) s.erase(tail);
			if(*s.begin()<pre_max)
				cnt-=(i-j+1ll)*(pre_max-(*s.begin())),
				pre_max=(*s.begin());
		}
		ans=max(ans,i-j+1);
	}
	cout<<ans;
	
	return 0;
}