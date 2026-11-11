#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[500005],b[500005];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(nullptr);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		b[i]=b[i-1]+a[i];
	}
	int ans=1;
	for(int i=2;i<=n;i++){
		int l=1,r=i-1;
		while(l<=r){
			const int mid=(l+r)/2;
			const int k=(i-mid)*a[i]-(b[i-1]-b[mid-1]);
			if(k<=m){
				ans=max(ans,i-mid+1);
				r=mid-1;
			}else{
				l=mid+1;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}

