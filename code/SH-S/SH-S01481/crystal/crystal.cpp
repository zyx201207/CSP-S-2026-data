#include<bits/stdc++.h>
using namespace std;
long long n,m,a[10000005];
int check(long long mid){
	long long sum=0;
	for(int i=1;i<=mid;i++){
		sum+=a[mid]-a[i];
	}
	if(sum>=m) return true;
	else return false;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	long long l=1,r=n;
	while(l<r){
		long long mid=l+(r-l)/2;
		if(check(mid)){
			r=mid;
		}
		else{
			l=mid+1;
		}
	}
	for(int i=l;i<=n;i++){
		if(a[l]==a[l+1]) l++;
	}
	cout<<l;
	return 0;
}

