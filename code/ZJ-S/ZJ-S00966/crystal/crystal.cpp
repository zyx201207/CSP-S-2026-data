#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10;
int n,m;
int a[N];
bool check(int x){
	int sum=m;
	for(int i=1;i<=x;i++){
		sum-=(a[x]-a[i]);
		if(sum<0)return 0;
	}
	return 1;
}
int erfen(int l,int r){
	while(l<r){
		int mid=l+(r-l+1)/2;
		if(check(mid)){
			l=mid;
		}else{
			r=mid-1;
		}
	}
	return l;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	cout<<erfen(1,n);
	
	
	
	return 0;
}