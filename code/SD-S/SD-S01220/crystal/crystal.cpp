#include<bits/stdc++.h>
using namespace std; 
#define int long long
int n,m;
int a[501000];
bool check(int mid){
	int sum=0;
	for(int i=1;i<=mid;i++){
		sum+=a[mid]-a[i];
	}
	return sum<=m;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int l=1,r=n;
	sort(a+1,a+n+1);
	while(l<r){
		int mid=(r+l+1)/2;
		if(check(mid)){
			l=mid;
		}
		else{
			r=mid-1;
		}
	}
	cout<<l;
	return 0;
}
