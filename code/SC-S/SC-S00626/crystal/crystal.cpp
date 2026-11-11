#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int m,a[N],b[N],ans;
bool check(int l,int r){
	return b[r]-b[l]-(l-1)*(a[r]-a[l])<=m;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n>>m;
	if(n==1){
		cout<<1;
		return 0;
	}
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	b[1]=0;
	for(int i=2;i<=n;i++) b[i]=b[i-1]+(i-1)*(a[i]-a[i-1]);
	for(int i=1;i<=n;i++){
		int l=1,r=i;
		while(l<=r){
			int mid=l+r>>1;
			if(check(mid,i)) r=mid-1,ans=max(ans,i-mid+1);
			else l=mid+1;
		}
	}
	cout<<ans;
	return 0;
}