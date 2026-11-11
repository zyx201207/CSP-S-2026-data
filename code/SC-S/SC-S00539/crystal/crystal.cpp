#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
const int N=500010;
int a[N];
int pre[N];
int ask(int l,int r){
	return (r-l+1)*a[r]-(pre[r]-pre[l-1]);
}
signed main(){
	ios::sync_with_stdio(0);cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	int ans=0;
	for(int i=1;i<=n;i++){
		pre[i]=pre[i-1]+a[i];
	}
	for(int i=1;i<=n;i++){//左区间
		int l=i,r=n;
		while(l<=r){
			int mid=(l+r)/2;
			if(ask(i,mid)>m)r=mid-1;
			else l=mid+1;
		}
		ans=max(l-i,ans);
	}
	cout<<ans;
	return 0;
}