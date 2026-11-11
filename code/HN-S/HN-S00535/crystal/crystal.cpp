#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005];
long long sum=0;
bool check(long long x){
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(a[i]<=x){
			cnt++;
		}
	}
	int ans=0;
	for(int i=1;i<=cnt;i++){
		ans+=x-a[i];
	}
	if(ans<=m){
		return 1;
	}else{
		return 0;
	}
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	long long l=1,r=856555555,mid=0;
	while(l<=r){
		mid=(l+r)/2;
		if(check(mid)){
			l=mid+1;
		}else{
			r=mid-1;
		} 
	}
	for(int i=1;i<=n;i++){
		if(a[i]<=mid){
			sum++;
		}
	}
	cout<<sum;
	return 0;
}
