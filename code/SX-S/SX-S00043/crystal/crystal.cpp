#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+1;
int n,m,a[N],dp[N],ans,k,g[N],ct,t[N],ij,pl;
int erfen(int x){
	int l=1,r=n;
	int mid=(l+r)/2;
	while(l<=r){
	if(a[mid]<x){
			l=mid+1;
		}else if(a[mid]>x){
			r=mid-1;
		}else{
			return mid;
		}
		mid=(l+r)/2;
	}
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		t[i]=t[i]-t[i-1];
		if(a[i]!=i){
			ij=1;
		}
	}
	if(ij==0){
		int u=n;
		while(m){
			ans++;
			m-=n-u;
			u--;
			if(m<0) break;
		}
		cout<<ans-1;
		return 0;
	}
	t[1]=0;
	sort(a+1,a+n+1);
 g[1]=0;
 for(int i=2;i<n;i++){
 	if(a[i]-a[i-1]!=a[i+1]-a[i]){
 		pl=1;
 		break;
	 }
 }
 if(pl==1){
	int u=n;
		while(1){
			ans++;
			m-=(a[2]-a[1])*(n-u);
			u--;
			if(m<0) break;
		}
		cout<<ans-1;
		return 0;
 }
	for(int i=2;i<=n;i++){
		g[i]=(a[i]-a[i-1])*(i-1)+g[i-1];
	}
	for(int i=1;i<=n;i++){
		if(g[i]<=m) k=i;
}
ans=k;
 for(int i=k+1;i<=n;i++){
 	ct=m;
  ct-=g[i];
  int p=2;
 	while(ct<0){
 		ct+=t[p++]*(i-p+1);
	 }
	ans=max(i-p+2,ans);
 }
 cout<<ans;
return 0;
}