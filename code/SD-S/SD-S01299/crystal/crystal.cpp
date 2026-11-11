#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+10;
int n;
ll m;
ll a[N];
ll q[N];
int ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		q[i]=q[i-1]+a[i];
	}
	for(int i=1;i<=n;i++){
		int l=1,r=i;
		while(l<=r){
			int mid=l+r>>1;
			if(a[i]*mid-(q[i]-q[i-mid])<=m) l=mid+1;
			else r=mid-1;
		}
		ans=max(ans,r);
	}
	cout<<ans;
	return 0;
}

