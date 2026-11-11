#include<bits/stdc++.h>
#define int long long
#define inf (1e18+7)
using namespace std;
const int N=5e5+5;
int n,m,a[N],mx=-inf,dis[N],predis[N],ans=-inf; 
signed main(){
	cin.tie(0)->sync_with_stdio(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mx=max(mx,a[i]);
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		dis[i]=mx-a[i];
	}
	for(int i=1;i<=n;i++){
		predis[i]=predis[i-1]+dis[i];
	}
//	for(int i=1;i<=n;i++)cout<<dis[i]<<" ";
//	cout<<endl;
//	for(int i=1;i<=n;i++)cout<<predis[i]<<' ';
//	cout<<endl;
	int l=1,r=0;
	while(r<n){
		r++;
		int nowmx=a[r];
		while(l<=r){
			int len=r-l+1;
			int val=predis[r]-predis[l-1]-(mx-nowmx)*len;
//			cout<<l<<" "<<r<<" "<<val<<endl;
			if(val<=m)break;
			else l++;
		}
		ans=max(ans,r-l+1);
//		cout<<ans<<endl;
	}
	cout<<ans;
	return 0;
}
/*
5 8
-3 -1 2 2 7
*/ 
