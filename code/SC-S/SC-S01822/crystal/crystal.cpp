#include<bits/stdc++.h>
#define maxn 500007
#define ll long long
using namespace std;
int n;
ll m,a[maxn],c[maxn];
int ans=1;
bool check(int sd){
	ll k=0;
	for(int i=2;i<=sd;i++) k+=1ll*(a[i]-a[i-1])*(i-1);
	if(k<=m){
		return 1;
	}
	for(int i=sd+1;i<=n;i++){
		k=k-(c[i-1]-c[i-sd])+1ll*(a[i]-a[i-1])*(sd-1);
		if(k<=m){
			if(sd==315276) cout<<i<<'\n';
			return 1;
		}
	}
	return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++){
		c[i]=c[i-1]+(a[i]-a[i-1]);
	}
	int l=1,r=n;
	while(l<=r){
		int mid=((l+r)>>1);
		if(check(mid)) ans=mid,l=mid+1;
		else r=mid-1;
	}
	cout<<ans;
	return 0;
}