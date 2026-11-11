#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define endl '\n'
int n,m,s[500002],a[500002],mi=LLONG_MAX;
// (a[k]-a[k])+
bool ch(int x){
	int ll=0;
	for(int i=1;i<=n;i++){
		int j=i+x-1;
		if(j>n){
			break;
		}
//		for(int k=i;k<=j;k++){
//			ll+=(a[j]-a[k]);
//		}
		ll=a[j]*(x-1)-(s[j-1]-s[i-1]);
		if(ll<=m){
			return 1;
		}
	}
	return 0;
}
int ef(){
	int l=1,r=n,ans=0;
	while(l<=r){
		int mid=(l+r)>>1;
		if(ch(mid)){
			l=mid+1;
			ans=max(ans,mid);
		}else {
			r=mid-1;
		}
	}
	return ans;
}
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mi=min(mi,a[i]);
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		a[i]-=mi;
	}
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	cout<<ef();
	
}//3845
//315275
