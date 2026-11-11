#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int n,m,a[N],b[N],ans;
int calc(int l,int r){
	return (r-l+1)*a[r]-(b[r]-b[l-1]);
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;++i){
		b[i]=b[i-1]+a[i];
	}
	for(int i=1;i<=n;++i){
		int l=1,r=i;
		while(l<r){
			int mid=(l+r)/2;
			if(calc(mid,i)>m) l=mid+1;
			else r=mid;
		}
		if(calc(l,i)>m || l!=r) continue;
		ans=max(i-l+1,ans);
	}
	cout<<ans;
	return 0;
}
