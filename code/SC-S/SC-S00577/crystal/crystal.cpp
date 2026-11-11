#include<bits/stdc++.h>
#define ll long long 
using namespace std;
const int N=5e5+5;
int n;
ll m;
ll a[N],s[N];
int ans=-1;
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
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i]; 
	}
	for(int i=n;i>=1;i--){
		int l=1,r=i,mid,ret;
		while(l<=r){
			int mid=(l+r)/2;
			ll tmp=1ll*(i-mid+1)*a[i]-(s[i]-s[mid-1]);
			if(tmp<=m){
				r=mid-1;
				ret=mid;
			}else{
				l=mid+1;
			}
		}
		ans=max(ans,i-ret+1);
	}
	cout<<ans;
	return 0;
}
//My friend said if I cant get score higher than 16pts
//I must nvzhuang
//But now he has no chanse
//And if I get score higher than 200pts
//He will nvzhuang
//zhe xia ta ke can le