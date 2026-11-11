#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5+10;
int n,m,a[N],pre[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;++i)pre[i]=pre[i-1]+a[i];
	int ans=0;
	for(int i=1;i<=n;++i){
		int l=0,r=i+1;
		while(l<r-1){
			int mid=l+r>>1;
			if((i-mid+1)*a[i]-(pre[i]-pre[mid-1])<=m)r=mid;
			else l=mid;
		}
		ans=max(ans,i-r+1);
	}
	cout<<ans;
	return 0;
}
