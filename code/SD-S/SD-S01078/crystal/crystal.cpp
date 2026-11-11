#include<bits/stdc++.h> 
using namespace std;
#define ll long long 
#define N 500000
const ll MOD=1e9+7;
ll n,m,mx,ans,lx;
int is_a=1,is_b=1;
ll a[N],zhi[N];

void sol(){
	for(ll i=1;i<=n;i++){
		for(ll j=1;j<=i;j++){
			if(m>=abs((i-j+1)*a[i]-(zhi[i]-zhi[j-1])))ans=max(ans,i-j+1);
//			cout<<i<<"  "<<j<<"  "<<(i-j+1)*a[i]-(zhi[i]-zhi[j-1])<<"\n";
//			cout<<"ans  "<<ans<<"\n";
		}
	}
	cout<<ans;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
//	ios::sync_with_stdio(0);
//	cin.tie(0),cout.tie(0);
	
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
//	for(int i=2;i<=n-1;i++){
//		if(a[i]-a[i-1]!=a[i+1]-a[i])is_b=0;
//	}
//	if(is_b){
//		ll d=a[10]-a[9];
//		for(ll i=1;i<=n;i++){
//			if(m>=a[i]*i-(a[i]+a[1])*n/2)ans=max(ans,i);
//		}
//		cout<<ans;
//		return 0;
//	}
	sort(a+1,a+1+n);
	for(ll i=1;i<=n;i++){
		zhi[i]=zhi[i-1]+a[i];
	}
//	for(int i=1;i<=n;i++)cout<<a[i]<<" ";
//	
	sol();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
