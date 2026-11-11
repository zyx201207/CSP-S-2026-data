#include<bits/stdc++.h>
using namespace std;
int n;
long long m,a[500005];
bool cheak(int x){
	long long sum=0;
	for(int i=1;i<=x;i++){
		if(a[i]<a[x]){
			sum+=(a[x]-a[i]);
		}
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
	sort(a+1,a+1+n);
	long long l=0,r=n,ans=0;
	while(l<=r){
		long long mid=l+(r-l)/2;
		if(cheak(mid)){
			l=mid+1;
			ans=mid;
		}else r=mid-1;
	}
	cout<<ans;
	return 0;
} 
