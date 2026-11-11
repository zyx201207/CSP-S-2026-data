#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll n,m,minn,maxx,ans,res,last,cnt;
ll a[500100],sx[500100];
map<pair<int,int>,int>t;
map<int,int>dy;
bool ch(ll mid){
	ll w=0;
	for(int i=1;i<=n;i++){
		if(a[i]<=mid){
			w+=mid-a[i];
		}
	}
	if(m>=w)return 1;
	else return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		minn=min(minn,a[i]);
		maxx=max(maxx,a[i]);
	}
	sort(a+1,a+1+n);
	ll l=minn,r=maxx;
	while(l<r){
		
		ll mid=(l+r+1)/2;
		if(ch(mid)){
			ans=mid;
			l=mid+1;
		}else r=mid-1;
	}
	res=n;
	for(int i=1;i<=n;i++){
		if(a[i]>ans){
			res=i-1;
			break;
		}
	}
	cout<<res;
	return 0;
}
