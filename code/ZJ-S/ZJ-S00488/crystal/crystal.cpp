#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10;
int a[N],s[N];
int n,m;
bool check(int x){
	int mi=1e18;
	for(int i=x;i<=n;i++){
		mi=min(mi,(x-1)*a[i]-(s[i-1]-s[i-x]));
	}
	return mi<=m;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i]; 
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	int l=0,r=n,mid,ans;
	while(l<=r){
		mid=(l+r)>>1;
		if(check(mid)){
			ans=mid;
			l=mid+1;
		}
		else{
			r=mid-1;
		}
	}
	cout << ans;
	return 0;
}
