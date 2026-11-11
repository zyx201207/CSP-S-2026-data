#include<iostream>
#include<algorithm>
#define ll long long
using namespace std;
const int N=2e5+5;
ll a[N];
bool cmp(ll x,ll y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ll n,m,ans=-1,cnt=-1;
	bool flagB=1;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i-1){
			flagB=0;
		}
	}
	if(n==1){
		cout<<n;
		return 0;
	}
	if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				ans=max(ans,(a[i]&a[j]));
			}
		}
		cout<<ans;
		return 0;
	}
	if(m==1){
		sort(a+1,a+n+1,cmp);
		cout<<a[1];
		return 0;
	}
	if(m==n){
		ans=(a[1]&a[2]);
		for(int i=3;i<=n;i++){
			ans&=a[i];
		}
		cout<<ans;
		return 0;
	}
	if(m==n-1){
		ll ans1=-1;
		for(int i=1;i<=n;i++){
			if(i==1){
				ans=(a[2]&a[3]);
			}
			else{
				if(i==2){
					ans=(a[1]&a[3]);
				}
				else{
					ans=(a[1]&a[2]);
				}
			}
			for(int j=1;j<=n;j++){
				if(j==i){
					continue;
				}
				ans&=a[i];
			}
			ans1=max(ans1,ans);
		}
		cout<<ans1;
		return 0;
	}
	sort(a+1,a+n+1,cmp);
	cnt=(a[1]&a[2]);
	for(int i=3;i<=m;i++){
		cnt&=a[i];
	}
	ans=max(ans,cnt);
	cnt=(a[n]&a[n-1]);
	for(int i=2;i<=m;i++){
		cnt&=a[n-i];
	}
	ans=max(ans,cnt);
	cout<<ans;
	return 0;
}
