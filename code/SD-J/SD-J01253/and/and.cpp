#include <bits/stdc++.h>
using namespace std;
#define int long long
int n;
int m;
int a[200020];
int ans=-123456789;
void dg(int k,int s,int x){
	if(k==0){
		ans=max(ans,s);
		return;
	}
	if(k+x-1>n){
		return;
	}
	if(s<=ans){
		return;
	}
	dg(k-1,s&a[x],x+1);
	if(n!=0){
		dg(k,s,x+1);
	}
	return;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dg(m,1073741823,1);
	cout<<ans;
	return 0;
}

