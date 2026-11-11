#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	vector<int>a(n+1,-1e18),c(n,0);
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a.begin(),a.end());
	for(int i=1;i<n;i++){
		c[i]=a[i+1]-a[i];
	}
	int po=1,maxn=-1e9,sum=0,j=1;
	while(j<=n){
		sum+=po*c[j];
		if(sum>m){
			sum-=a[j+1]-a[j-po+1];
			po--;
		}
		po++;
		j++;
		maxn=max(maxn,po);
	}
	cout<<maxn;
}
