#include<bits/stdc++.h>
using namespace std;
#define int long long
int const N = 5e5+7;
int n,m,a[N],ans;
bool check(int mid){
	vector<int> k;
	for(int i=1;i<=n;i++){
		if(mid<a[i]) continue;
		k.push_back(mid-a[i]);
	}
	int sum = 0;
	for(int i:k){
		sum+=i;
	} 
	return sum<=m;
}
int get(int mid){
	int sum = 0;
	for(int i=1;i<=n;i++){
		if(mid>=a[i]) sum++;
	}
	return sum;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	int x;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	} 
	sort(a+1,a+n+1);
	int l=1,r=n;
	while(l<=r){ //二分终点能量 
		int mid = l+r>>1;
		if(check(a[mid])){
			ans = max(ans,get(a[mid]));
			l = mid+1;
		}
		else r = mid-1;
	}
	cout<<ans;
	return 0;
}
