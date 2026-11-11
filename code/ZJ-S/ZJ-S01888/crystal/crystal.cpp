#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int a[N],cf[N],erp[N],erp2[N];
int n,m;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];	
	}
	sort(a+1,a+1+n);
	for(int i=2;i<=n;i++){
		cf[i]=a[i]-a[i-1];
	}
	for(int i=n;i>=2;i--){
		erp[i]=cf[i]+erp[i+1];
	}
	for(int i=n;i>=2;i--){
		erp2[i]=erp2[i+1]+erp[i];
	}
	// ------------------------------------------------
	int ans=1;
	int l=1,r=n;
	while(l<r-1){
		int k=(l+r)/2;
		bool f=0;
		for(int i=1;i+k-1<=n;i++){
			if(erp2[i+1]-erp2[i+k]-(k-1)*erp[i+k]<=m){
				f=1;
				ans=k;
				break;
			}
		}
		if(!f){
			r=k-1;
		}
		else{
			l=k;
		}
	}
	cout<<ans;
	
	
	
	
	
	return 0;
}