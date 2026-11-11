#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+5;
ll n,m,a[N],s[N],Max=-1;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++) s[i]=s[i-1]+(a[i]-a[i-1])*(i-1);
	//for(int i=1;i<=n;i++) cout<<s[i]<<' ';
	for(int i=1;i<=n;i++){
		ll l=i,r=n,ans=-1;
		while(l<r){
			ll mid=(l+r)/2;
			if(s[mid]-s[i]-(i-1)*(a[mid]-a[i])<=m){
				l=mid+1;
				ans=max(ans,mid); 
			}else{
				r=mid-1; 
			}
		}
		ll mid=(l+r)/2;
		if(s[mid]-s[i]-(i-1)*(a[mid]-a[i])<=m){
			ans=max(ans,mid); 
		}
		if(Max<ans-i+1){
//			cout<<i<<' '<<ans<<endl;
			Max=ans-i+1;
		}
	}
	cout<<Max;
	return 0;
} 
