#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("crystal.out","w",stdout);
	freopen("crystal.in","r",stdin);
	vector<ll>num;
	ll n=0,m=0,x=0;
	cin>>n>>m;
	for(ll i=0;i<n;i++){
		cin>>x;
		num.push_back(x);
	}
	sort(num.begin(),num.end());
	ll l=0,r=0,ans=1,sp=0;
	while(r<n-1){
		r++;
		sp+=(num[r]-num[r-1])*(r-l);
		while(sp>m)sp-=num[r]-num[l],l++;
		ans=max(ans,r-l+1);
	}
	cout<<ans;
	return 0;
}
