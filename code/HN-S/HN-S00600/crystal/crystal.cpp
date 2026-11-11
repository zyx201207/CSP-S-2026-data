#include<bits/stdc++.h>
using namespace std;
using ll=long long; 
const int N=5e5+5;
int n,ans;
ll m;
ll a[N],s[N];
bool Check(int l,int r){
	ll cnt=(ll)(r-l)*a[r]-(s[r]-s[l]);
	return cnt<=m;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) s[i]=a[i]+s[i-1];
	for(int i=1;i<=n;i++){
		int l=0,r=i-1;
		while(l<r){
			int mid=l+r>>1;
			if(Check(mid,i)) r=mid;
			else l=mid+1;
		}
		ans=max(ans,i-l);
	}
	cout<<ans;
	return 0;
}

