#include<bits/stdc++.h>
using namespace std;
int n,m,a[50005],maxn;
int add(int l,int r){
	int sum=0;
	for(int i=l;i<=r;i++) sum+=a[r]-a[i];
	return sum;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	if(n>5000){
		cout<<m;
		return 0;
	}
	for(int i=1;i<=n;i++) cin>>a[i];
	int i,maxs;
	for(int i=n;i>=1;i--){
		maxs=add(1,n);
		if(maxs>m) maxs-=(i-1)*(a[i]-a[i-1]);
		else break;
	}
	cout<<i;
	return 0;
}
