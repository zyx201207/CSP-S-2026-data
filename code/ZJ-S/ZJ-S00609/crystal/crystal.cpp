#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m;
int a[N];
int b[N];
int solve(int x){
	int l=1,r=x;
	while(l<r){
		int mid=(l+r)>>1;
		if(a[x]*(x-mid)-(b[x-1]-b[mid-1])<=m){
			r=mid;
		}
		else{
			l=mid+1;
		}
	}
	return l;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		b[i]=b[i-1]+a[i];
	}
	int ans=1;
	for(int r=1;r<=n;r++){
		int l=solve(r);
		ans=max(ans,r-l+1);
	}
	cout<<ans;
	return 0;
}
