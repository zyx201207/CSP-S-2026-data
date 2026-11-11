#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500010];
bool check(int x){
	int sum=0;
	for(int i=1;i<x;i++){
		sum+=(a[x]-a[i]);
	}
	return sum<=m;
}
int main(){	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int l=1,r=n;
	int ans=0;
	while(l<=r){
		int mid=(l+r)/2;
		if(check(mid)){
			l=mid+1;
			ans=mid;
		}
		else{
			r=mid-1;
		}
	}
	cout<<ans;
		
	
	return 0;
}