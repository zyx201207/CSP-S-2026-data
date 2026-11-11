#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[500005],Sum[500005];
ll sum,ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(m==0){
		cout<<a[n];
		return 0;
	}
	ll d=a[2]-a[1];
	bool f=1;
	for(int i=2;i<=n;i++){
		if(a[i]-a[i-1]!=d){
			f=0;
			break;
		}
	}
	if(f==1){
		ll x=2*m/d;
		ll k=sqrt(1+4*x);
		cout<<(k+1)/2;
		return 0;
	}
	for(int i=1;i<=n;i++){
		ll sum=0;
		for(int j=1;j<=i;j++){
			sum+=(a[i]-a[j]);
		}
		if(sum>m){
			break;
		}
		else{
			ans=i;
		}
	}
	cout<<ans;
	return 0;
}

