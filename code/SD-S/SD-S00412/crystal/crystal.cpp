#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=5e5+10;
ll n,m;
ll a[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	ll s,ans=0;
	for(int i=1;i<=n;i++){
		s=0;
		ans=i;
		for(int j=1;j<i;j++){
			s+=a[i]-a[j];
		}
		if(s>m){
			cout<<ans-1;
			return 0;
		}
	}
	cout<<n;
	return 0;
} 
