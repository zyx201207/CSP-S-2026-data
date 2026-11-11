#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=5e5+50;
int a[maxn],p[maxn];
int n,m,start=1,ans=-1e18;

bool pd(int s){
	if (start+s-1>n) return 0;
	int cnt=0,k=a[start+s-1];
	
	return k*s-(p[start+s-1]-p[start-1])<=m;
}

signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin>>n>>m;
	for (int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for (int i=1;i<=n;i++) p[i]=p[i-1]+a[i];
	for (start=1;start<=n;start++){
		int l=1,r=5e5+50;
		while (l<=r){
			int mid=(l+r)/2;
			if (pd(mid)){
				l=mid+1;
			}else r=mid-1;
		}
		ans=max(ans,r);
	}
	cout<<ans<<endl;
	return 0;
}

//Oct31==Dec25?

