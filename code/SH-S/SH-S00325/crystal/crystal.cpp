#include<bits/stdc++.h>
using namespace std;
int n;
long long m;
long long a[500005],p[500005];
bool c(int mid){
	long long mi=1e18;
	for(int i=mid;i<=n;i++){
		mi=min(mi,a[i]*mid-(p[i]-p[i-mid]));
		cout<<a[i]*mid-(p[i]-p[i-mid])<<' ';
	}
	cout<<'\n';
	return mi<=m;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		p[i]=p[i-1]+a[i];
	}
	int l=0,r=n,ans;
	while(l<=r){
		int mid=(l+r)/2;
		if(c(mid)){
			l=mid+1;
			ans=mid;
		}else{
			r=mid-1;
		}
	}
	cout<<ans<<'\n';
	return 0;
}
/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7
*/

