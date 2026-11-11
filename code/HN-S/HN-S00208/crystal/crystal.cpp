#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long n,m,l,r,ans,a[N];
bool check(int k){
	long long x=0,y=0;
	for(int i=1;i<=n;i++){
		if(a[i]<=k){
			x+=k-a[i];
			y++;
		}
	}
	if(x<=m){
		ans=y;
		return 1;
	}
	return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		l=min(l,a[i]);
		r=max(r,a[i]);
	}
	while(l<=r){
		long long mid=(l+r)>>1;
		if(check(mid)){
			l=mid+1;
		}else{
			r=mid-1;
		}
	}
	cout<<ans;
	return 0;
}
