#include<bits/stdc++.h>
using namespace std;

using ll=long long;
int n;
ll m;
vector<ll> a;

bool pro(ll idx,int s){
	ll rest=m;
	int st=lower_bound(a.begin(),a.end(),idx)-a.begin()-1,cnt=0;
	for(int i=st+1;i<n;i++){
		if(a[i]==idx) cnt++;
		else break;
	}
	if(cnt>=s) return 1;
	for(int i=st;i>=0;i--){
		if(rest>=(idx-a[i])){
			cnt++;
			if(cnt>=s) return 1;
			rest-=(idx-a[i]);
		}
		else break;
	}
	return 0;
}

bool check(int s){
	int l=(n-1)>>1,r=n>>1;
	while(l>=0 && r<n){
		if(pro(a[l],s) || pro(a[r],s)) return 1;
		l--;r++;
	}
	return 0;
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	a.resize(n);
	for(int i=0;i<n;i++) scanf("%lld",&a[i]);
	sort(a.begin(),a.end());
	int l=1,r=n;
	while(l<r){
		int mid=(l+r+1)>>1;
		if(check(mid)) l=mid;
		else r=mid-1;
	}
	printf("%d\n",l);
	return 0;
}