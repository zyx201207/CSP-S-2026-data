#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+5;
ll n,a[N],cnt,s[N],ans=1;
unsigned ll m;
bool check(ll l,ll r){
	unsigned ll x=((r-l+1)*a[r]-(s[r]-s[l-1]));
//	if(x<=m)
//	cout<<m<<' '<<' '<<x<<endl;
	return (x)<=m;
}
int main(){
	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
	a[0]=-1e13;
	a[n+1]=-1e13;
	for(int i=1;i<=n;i++){
//		if(a[i]==a[i-1])cnt++;
//		else cnt=1;
//		if(a[i]==a[i+1]){
//			continue;
//		}
		ll l=1,r=i;
		while(l<=r){
			ll mid=(l+r)/2;
			if(check(mid,i)){
				r=mid-1;
//				if(i-mid+1>ans){
//					cout<<mid<<' '<<i<<endl;					
//				}
				ans=max(ans,i-mid+1);

			}else{
				l=mid+1;
			}
		}
	}
	cout<<ans<<endl;
	
	return 0;
} 
