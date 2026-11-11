#include<bits/stdc++.h>
using namespace std;
long long a[500010];
int n;
long long m;
bool chk(long long mid){
	long long sum=0;
	for(int i=1;i<=n;i++){
		if(mid>=a[i]){
			sum+=mid-a[i];
		}
	}
	return sum<=m;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	long long mn=2e9,mx=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mn=min(mn,a[i]);
		mx=max(mx,a[i]);
	}
	int l=mn,r=mx;
	int ans=0;
	long long mid;
	while(l<=r){
		mid=l+(r-l)/2;
		if(chk(mid)){
			l=mid+1;
			ans=mid;
		}else{
			r=mid-1;
		}
	}
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(a[i]<=ans){
			cnt++;
		}
	}cout<<cnt;
	return 0;
}
