#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull; 
ll n,cm£¬m;

vector<ll> a;
ll ans,nans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	cm=m;
	a.resize(n);
	for(ll i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a.begin(),a.end());
	for(int i=n-1;i>=0;i--){
		nans=0;
		m=cm;
		for(int j=i-1;j>=0;j--){
			ll tmp=a[i]-a[j];
			if(m-tmp>=0){
				nans++;
				m=m-tmp;	
			}
		}
		ans=max(ans,nans);
		if(ans==n-1){
			break;
		}
	}
	cout<<ans+1;
	return 0;
} 
