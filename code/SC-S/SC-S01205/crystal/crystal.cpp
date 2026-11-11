#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long n,m,a[N],sum[N],l,r,mid,mn;
bool check(){
	mn=9e18;
	for(int i=mid;i<=n;i++){
		mn=min(mn,a[i]*mid-(sum[i]-sum[i-mid]));
	}
	return mn<=m;
}
int main(){
	//根本没有这么简单的S组T1 awa 
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
	
	l=1,r=n;
	while(l<r){
		mid=(l+r+1)/2;
		if(check())l=mid;
		else r=mid-1;
	}
	cout<<l;
	return 0;
} 