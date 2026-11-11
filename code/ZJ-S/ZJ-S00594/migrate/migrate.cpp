#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+5;
int c,t,a[N];
bool half(int x,int n){
	int l=1,r=n,mid;
	while(l<=r){
		mid=l+((r-l)>>1);
		if(a[mid]==x) return 1;
		else if(a[mid]<x) l=mid+1;
		else r=mid-1;
	}
	return 0;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>t;
	while(t--){
		int n,d,ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=1;i<=n;i++){
			int x=a[i];
			if(x+2*d-1>n) break;
			if(half(x+d-1,n)&&half(x+d,n)&&half(x+2*d-1,n)) ans++;
		}
		cout<<ans<<"\n";
	}
	return 0;
}