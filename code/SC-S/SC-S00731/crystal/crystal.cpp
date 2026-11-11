#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll n,m,ans,sum;
vector<ll> a;

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin>>n>>m;
	for(ll i=0;i<n;i++){
		int v;
		cin>>v;
		sum+=v;
		a.push_back(v);
	}
	sum=sum+m;
	if(sum%n!=0){
		sum=sum/n-1;
	}else{
		sum/=n;
	}
	for(int i=0;i<n;i++){
		if(sum>=a[i]){
			ans++;
		}
	}
	cout<<ans;
	
	return 0;
}