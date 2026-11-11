#include <bits/stdc++.h>
#define ll long long
using namespace std;
struct node{
	ll data,cnt;
	bool operator<(const node& o)const{
		return this->data<o.data;
	}
	bool operator>(const node& o)const{
		return this->data<o.data; 
	}
	bool operator<(const ll& i)const{
		return this->data<i;
	}
};
int main(){
	freopen("crystal4.in","r",stdin);
	freopen("crystal4.out","w",stdout);
	ll n,m,ans=-1000000000000000009ll;
	cin>>n>>m;
	const ll gt=500005ll;
	vector<bool> vis(1000010,false);
	vector<node> cnt;//cnt(500005,0);
	for(int i=1;i<=n;i++){
		ll a;
		cin>>a;
		if(vis[a+gt]){
			ll l=0,r=cnt.size()-1,mid;
			while(l<r){
				mid=(l+r)>>1;
				if(cnt[mid]<a) l=mid+1;
				else r=mid-1;
			}
			cnt[mid].cnt++;
		}
		else{
			cnt.push_back({a,1});
			sort(cnt.begin(),cnt.end());
			vis[a+gt]=true;
		}
		//x=max(x,a);
		//y=min(y,a);
	}
	//ll f=0;
	//printf("{%lld,%lld}\n",x,y);
	for(ll i=0;i<cnt.size();i++){
		if(!vis[i+gt]) continue;
		ll k=m;
		ll as=cnt[i].cnt;
		for(ll j=i-1;j>=0;j--){
			if(k<i-cnt[j].data) break;
			if(!vis[i+gt]) continue;
			vector<node> bs=cnt;
			while(k>=i-cnt[j].data&&bs[j].cnt>0){
				bs[j].cnt--;
				as++;
				k-=bs[j].data;
			}
		}
		ans=max(ans,as);
	}
	printf("%lld\n",ans);
	return 0;
}
