#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
int n,m;
int a[N],sub[N],pre[N];
bool check(int len){//		cout<<len<<endl;
	for(int l=1;l+len-1<=n;l++){
		int r=l+len-1;
//		if(len==314453) 
//			cout<<pre[r]-pre[l-1]<<" ";
		if(pre[r]-pre[l-1]-(a[r]-a[l-1])*(l-1)<=m) return true;
	}
	return false;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=2;i<=n;i++){
		sub[i]=a[i]-a[i-1];
		pre[i]=sub[i]*(i-1)+pre[i-1];
	}
//	for(int i=1;i<=n;i++) cout<<a[i]<<' '; cout<<endl<<endl;
//	for(int i=1;i<=n;i++) cout<<sub[i]<<' ';	cout<<endl;
//	for(int i=1;i<=n;i++) cout<<pre[i]<<' ';cout<<endl;
	int l=1,r=n;
	while(l<=r){
		int mid=(l+r)/2;
		if(check(mid)) l=mid+1;
		else r=mid-1;
	}
	cout<<r;
	
	
	return 0;
}
