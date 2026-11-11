#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
int n,m;
int a[N],b[N];
int ans;

bool check(int l,int r){
	int need=(r-l+1)*a[r];
	int sum=b[r]-b[l-1];
	if(sum+m>=need)return true;
	return false;
}

void solve(int R){
	int l=1,r=R;
	while(l<=r){
		int mid=(l+r)>>1;
		if(check(mid,R))r=mid-1;
		else l=mid+1;
	}
	ans=max(ans,R-r);
}

signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i)cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;++i)b[i]=b[i-1]+a[i];
	for(int i=1;i<=n;++i)solve(i);
	cout<<ans;
	return 0;
}
