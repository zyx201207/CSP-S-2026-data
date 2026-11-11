#include<bits/stdc++.h>
using namespace std;
int n;
long long m,a[5000005],num[5000005],ans=0;
bool check(int x){
	for(int j=1;j<x;j++){
		num[x]+=a[x]-a[j];
		if(num[x]>m){
			return 0;
		} 
	}
	return 1;
}
void bs(){
	int l=1,r=n;
	while(l<=r){
		long long mid=l+(r-l)/2;
		if(check(mid)){
			ans=mid;
			l=mid+1;
		}
		else{
			r=mid-1;
			
		}
		
	}
	return;
}
long long cnt[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	bs();
	cout << ans;
	return 0;
} 
