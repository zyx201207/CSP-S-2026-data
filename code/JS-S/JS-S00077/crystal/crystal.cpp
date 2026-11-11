#include<bits/stdc++.h>
using namespace std;
using ll=long long;
struct NODE{
	ll num;
	int cs;
};
ll n,m;
vector<ll>a;
vector<NODE>js;
ll cal(int maxx,int xb){
	int jl=0;
	ll hf=0ll;
	while(maxx){
		hf+=(min(js[xb-jl].cs,maxx)*(js[xb].num-js[xb-jl].num));
		maxx-=js[xb-jl].cs;
		jl++;
		if(maxx<0) maxx=0;
	}
	return hf;
}
bool check(int maxx){
	int s=0;
	ll need=LLONG_MAX;
	for(int i=0;i<n;i++){
		s+=js[i].cs;
		if(!js[i].cs) break;
		if(s>=maxx){
			need=min(need,cal(maxx,i));
		}
	}
	if(need<=m) return true;
	return false;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	a.assign(n,0ll);
	js.assign(n,{0ll,0ll});
	for(int i=0;i<n;i++) cin>>a[i];
	sort(a.begin(),a.end());
	js[0]={a[0],1};
	for(int i=1,xb=0;i<n;i++){
		if(a[i]==js[xb].num) js[xb].cs++;
		else{
			xb++;
			js[xb]={a[i],1};
		}
	}
	int l=1,r=n,mid,ans;
	while(l<=r){
		mid=(r-l)/2+l;
		if(check(mid)){
			ans=mid;
			l=mid+1;
		}
		else r=mid-1;
	}
	cout<<ans;
	return 0;
}
