#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n;
ll m;
ll a[567890];
ll b[567890];
bool check(int x,int i){
	return x*a[i]-(b[i-1]-b[i-x-1])<=m;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	ll ans=-1145141919810;
	for(int i=1;i<=n;i++)b[i]=b[i-1]+a[i];
	for(int i=2;i<=n;i++){
		ll l=0,r=i-1;
		while(l<=r){
			int mid=l+r>>1;
			if(check(mid,i))l=mid+1;
			else r=mid-1;
		}ans=max(ans,l);
	}cout<<ans;
	return 0;
} 
