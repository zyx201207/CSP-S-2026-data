#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=5e5+10;
priority_queue<ll,vector< ll > > v;

ll n,m;
ll a[maxn],num[maxn];
ll sum;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	if(n==1){
		cout<<1;
		return 0;
	}
	for(ll i=1;i<=n;i++){
		int t;
		cin >> t;
		v.push(t);
	}
	for(ll i=n;i>=1;i--){
		a[i]=v.top();
		v.pop();
	}

	//for(ll i=1;i<n;i++){
	//	num[i]=a[n]-a[i];
	//}
	ll l=1,r=n;
	ll ans=0;
	while(l<=r){
		ll mid=(l+r)/2;
		sum=0;
		for(ll i=1;i<mid;i++){
			sum+=a[mid]-a[i];
		}
		if(sum>m){
			r=mid-1;
			if(l>r)break;
		}else if(sum<=m){
			l=mid+1;
			if(l>r)break;
			ans=mid;
		}
	}
	cout<<ans;
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
} 