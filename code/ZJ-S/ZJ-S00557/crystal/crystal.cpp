#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int a[N],cha[N],t[N],t1[N];
int n,m;
int solve(int l,int r){
	return t[r]-t[l]-(t1[r]-t1[l])*(l-1);
}
bool cheak(int l,int r){
	int ans=solve(l,r);
	if(ans<=m) return 1;
	return 0;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<n;i++) cha[i]=a[i+1]-a[i];
	for(int i=1;i<=n;i++) t[i]=t[i-1]+cha[i-1]*(i-1);
	for(int i=1;i<=n;i++) t1[i]=t1[i-1]+cha[i-1];
	int maxx=1;
	for(int i=1;i<=n;i++){
		int l=1,r=i;
		while(l<r){
			int mid=(l+r)/2;
			if(cheak(mid,i)) r=mid;
			else l=mid+1;
		}
		maxx=max(maxx,i-l+1);
	}
	cout<<maxx<<"\n";
	return 0;
}