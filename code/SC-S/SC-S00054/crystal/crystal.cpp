#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,m;
int a[N];
int b[N];
int sum[N];
bool cmp(int a,int b){
	return a<b;
}
int ans;
bool check(int l,int r){
	if(a[r]*(r-l+1)-(sum[r]-sum[l-1])<=m){
		return 1;
	}else{
		return 0;
	}
}
void solve(int x){
	int l=0,r=x+1;
	while(l+1<r){
		int mid=(l+r)/2;
		if(check(mid,x)){
			r=mid;
		}else{
			l=mid;
		}
	}
//	int id=lower_bound(a+1,a+1+x,sum[x]+m-a[x]*x)-a;
	ans=max(ans,x-r+1);
//	cout<<l<<' ';
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
//	int b[]={0,1,2,3,4,5,5,6,6,6};
//	cout<<upper_bound(b+1,b+8,5)-b;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	for(int i=1;i<=n;i++){
		solve(i);
	}
	cout<<ans;
	return 0;
}
/*
5 5
1 2 4 8 9
5 8
-3 -1 2 2 7
*/