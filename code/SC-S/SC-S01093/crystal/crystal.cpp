#include<bits/stdc++.h>
using namespace std;
const int N=500005;
long long ans,n,a[N],sum[N],m;
bool check(int k,int r){
	int h=k*a[r]-(sum[r]-sum[r-k]);
	if(h<=m)return true;
	else return false;
}
int lb(int sx){
	int l=1,r=sx,mmax=-1;
	while(l<=r){
		int mid=(l+r)>>1;
		if(check(mid,sx)){
			mmax=max(mmax,mid);
			l=mid+1;
		}else{
			r=mid-1;
		}
	}
	return mmax;
}
priority_queue<int>q;
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		q.push(-a[i]);
	}
	for(int i=1;i<=n;i++){
		a[i]=-q.top();
		q.pop();
		sum[i]=sum[i-1]+a[i];
	}
	for(int i=1;i<=n;i++){
		long long u=lb(i);
		ans=max(ans,u);
	}
	cout<<ans;
	return 0;
}