#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int n,m;
int a[N],q[N],c[N];
int check(int nw,int val){
	int ans=1e9;
	int l=1,r=nw,mid=0;
	while(l<=r){
		mid=(l+r)>>1;
		int jz=c[nw]-(c[mid]+(a[nw]-a[mid])*(mid-1));
		if(val>=jz){
			r=mid-1;
			ans=min(ans,mid);
		}else{
			l=mid+1;
		}
	}
	return ans;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){cin>>a[i];}
	sort(a+1,a+1+n);
	for(int i=2;i<=n;i++){
		q[i]=a[i]-a[i-1];
		c[i]=c[i-1]+q[i]*(i-1);
	}
	int res=1;
	for(int i=1;i<=n;i++){
		//cout<<check(i,m)<<" ";
		res=max(i-check(i,m)+1,res);
	}
	cout<<res;
	
	return 0;
}
/*
5 8
-3 -1 2 2 7
*/
