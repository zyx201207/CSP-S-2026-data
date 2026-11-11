#include<bits/stdc++.h>
using namespace std;
const int N=6e5+10;
long long n,m,a[N],sum[N],ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}	
	long long l=1,r=2;
	while(l<r&&r<=n&&l<=n){
		if((r-1)*a[r]-(sum[r-1]-sum[l-1])<=m){
			r++;
		}
		else{
			l++;
		}	
		ans=max(ans,r-l);
	}
	cout<<ans;
	return 0;
}
/*
5 8
-3 -1 2 2 7
*/
