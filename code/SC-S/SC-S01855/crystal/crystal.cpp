#include<bits/stdc++.h>
using namespace std;
using ll=long long;

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	int n;ll m;
	cin>>n>>m;
	if(n>5000){
		ll a,b,ans=0;
		cin>>a>>b;
		ll num=abs(a-b),sum=0;
		for(int i=1;i;i++,sum+=i){
			if(m>=(sum*num))ans++;
			else break;
		}
		cout<<ans;
		return 0;	
	}
	vector<ll>A(n),B(n+5,0);
	for(int i=0;i<n;i++){
		cin>>A[i];
	}
	sort(A.begin(),A.end());
	ll ans=1;
	for(int i=1;i<n;i++){B[i]=B[i-1]+(i*(A[i]-A[i-1]));}
	for(int i=1;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(m>=(B[j]-B[i])){
				ans=max(ans,ll(j-i+2));
			}
			else break;
		}
	}
	cout<<ans;
	return 0;
}
