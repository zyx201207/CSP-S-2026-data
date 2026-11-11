#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[500010],dy[500010],sdy[500010],ssdy[500010],ans=1;
int query1(int l,int r){
	r--;
	return ssdy[l]-ssdy[r+1];
}
int query(int l,int r){
	return query1(l,r)-sdy[r]*(r-l);
}
bool check(int l,int r){
	if (query(l,r)>m)return 0;
	else return 1;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for (int i=2;i<=n;i++){
		dy[i]=a[i]-a[i-1];
	}
	for (int i=n-1;i>=1;i--){
		sdy[i]=sdy[i+1]+dy[i];
		ssdy[i]=ssdy[i+1]+sdy[i];
	}
	for (int r1=n;r1>=1;r1--){
		int l=1,r=r1,mid;
		while (l<r){
			mid=(l+r)/2;
			if (check(mid,r1))r=mid;
			else l=mid+1;
		}
		int dis=r1-r+1;
		ans=max(ans,dis);
	}
	cout<<ans;
	return 0;
}

