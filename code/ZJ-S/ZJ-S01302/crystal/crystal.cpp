#include<bits/stdc++.h>
using namespace std;
#define int long long
#define A LONG_LONG_MAX
#define B LONG_LONG_MIN
int n,m,i,a[500100],b[500100],ans;
int pd(int x){
	int mi=A;
	for(int i=x;i<=n;i++){
		mi=min(mi,(a[i]*x-(b[i]-b[i-x])));
	}
	return mi;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(i=1;i<=n;i++) b[i]=a[i]+b[i-1];
	int t=1,w=n;
	while(t<=w){
		int mid=(t+w)>>1;
		if(pd(mid)<=m) t=mid+1,ans=mid;
		else w=mid-1;
	}
	cout<<ans;
	return 0;
}

