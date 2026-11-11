#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=2e5+10;
ll n,a[N],cnt[N],ans,len;
char c[N];
vector<pair<ll,char> > t;
char col(ll pos){
	ll x=upper_bound(cnt+1,cnt+n+1,pos)-cnt-1;
	return c[x];
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(ll i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		if(i!=1) cnt[i]=cnt[i-1]+a[i-1];
		else cnt[i]=1;
		t.push_back({cnt[i],c[i]});
		len+=a[i];
	}
	cnt[n+1]=len+1;
	for(ll i=1;i<=n;i++){
		t.push_back({len-t[i-1].first+2,col(len-t[i-1].first+2)});
	}
	sort(t.begin(),t.end());
	t.erase(unique(t.begin(),t.end()),t.end());
	ll l=0,r=t.size()-1;
	if(t[r].first>len) r--;
	while(l<=r){
		if(t[l].second!=t[r].second){
			ans+=t[l+1].first-t[l].first;
		}
		l++,r--;
	}
	cout<<ans;
	return 0;
}
