#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct bs{
	ll en;
	bool vi;
}a[500005];
struct ch{
	ll ca;
	ll idx;
}c[500005];
ll n,m;
bool cmp1(bs x,bs y){
	return x.en<y.en;
}
bool cmp2(ch x,ch y){
	return x.ca<y.ca;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i].en;
		a[i].vi=false;
	}
	sort(a+1,a+n+1,cmp1);
	int k=1;
	int ans=0;
	int cnt=n;
	a[n+1].en=LONG_LONG_MAX;
	for(int i=1;i<=n;i++){
		c[i].ca=a[i+1].en-a[i].en;
		c[i].idx=i;
	}
	while(cnt>0&&m>0){
		for(int i=k;i<=n;i++){
			c[i].ca=a[i+1].en-a[i].en;
		}
		sort(c+k,c+n+1,cmp2);
		if(a[c[k].idx].vi==false){
			ans++;
		}
		if(a[c[k].idx+1].vi==false){
			ans++;
		}
		a[c[k].idx+1].en+=a[c[k].idx].en+1;
		k++;
		m--;
		cnt--;
	}
	cout<<ans;
	return 0;
}
