//crystal.cpp
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+5;
const ll inf=2e18;
ll n,m;
ll a[N];
bool check(int mid){
	ll tot=0;
	for(int i=1;i<=mid;i++){
		if((ll)(tot+(ll)abs(a[mid]-a[i]))>inf)
			return 0;
		tot+=abs(a[mid]-a[i]);
	}
	return tot<=m; 
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
 	cin>>n>>m;
 	for(int i=1;i<=n;i++){
 		cin>>a[i];
	}
	sort(a+1,a+1+n);
	ll tot=0;
	/*for(int i=1;i<=315275;i++){
		tot+=abs(a[315275]-a[i]);
	}
	cout<<tot<<"\n"<<m;
	*/
	int l=1,r=n+1,ans;
	a[n+1]=inf;
	while(l<r){
		int mid=(l+r)/2;
		//cout<<l<<" "<<r<<" "<<mid<<"\n";
		if(check(mid)){
			l=mid+1;
			ans=mid;
		}
		else r=mid;
	}
	ll p=upper_bound(a+1,a+1+n,a[ans])-a-1;
	cout<<p<<"\n";
	return 0;
}