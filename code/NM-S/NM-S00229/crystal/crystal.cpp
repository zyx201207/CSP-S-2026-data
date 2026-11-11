#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+5;
ll a[N],cha[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ll n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}	
	sort(a+1,a+n+1);
		for(int i=2;i<=n;i++){
		cha[i]=a[i]-a[i-1];
	}
	ll ans=0;
	if(n<=16){
		for(int i=2;i<=n;i++){
		if(m-(i-1)*cha[i]<0) break;
		m-=(i-1)*cha[i];
		ans++;
		} 	
	}
	else{
		ll d=a[2]-a[1];
		int i=1;
		while(m-i*d>=0){
			m=m-i*d;
			ans++;
			i++;
		}
	}
	cout<<ans+1;
	return 0;
}
