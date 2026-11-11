#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int n,m;
int a[N];
int b[N];
int ans;
int t[N];
bool cmp(int a,int b){
	return a>b;
}
int f(int l,int r){
	int x=(r-l+1)*a[r]-(t[r]-t[l-1]);
	return x;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		t[i]=t[i-1]+a[i];
	} 
//	cout<<f(1,3);
	for(int l=1,r=1;l<=n;l++){
		while(r<n&&f(l,r+1)<=m)r++;
		ans=max(ans,r-l+1);
//		cout<<l<<' '<<r<<'\n';
	}
	cout<<ans;
	return 0;
} 
