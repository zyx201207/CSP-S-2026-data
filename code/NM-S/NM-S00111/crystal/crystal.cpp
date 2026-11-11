#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
typedef long long ll;
const ll maxn=5e5+10;
ll n,arr[maxn],m,l,r,mid,ans=-1;
bool IsAB=true,IsC=true; 
bool check(ll x){
	for (int i=1;i<=n-x;i++){
		ll tmp=0;
		for (int j=i;j<i+x-1;j++){
			tmp+=arr[i+x-1]-arr[j];
		}
		if (tmp<=m){
			return true;
		}
	}
	return false;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m;
	for (int i=1;i<=n;i++){
		cin >> arr[i];
		if (IsAB && i>2 && arr[i]!=2*arr[i-1]-arr[i-2]){
			IsAB=false;
		}if (IsC && i>1 && arr[i]!=arr[i-1]){
			IsC=false;
		}
	}
	if (n==1){
		cout << 1;
		return 0;
	}if (n==2){
		if (min(arr[1],arr[2])+m>=max(arr[1],arr[2])){
			cout << 2;
			return 0;
		}
		cout << 1;
		return 0;
	}
	if (IsC){
		cout << n;
		return 0;
	}
	if (IsAB){
		if (arr[1]<arr[2]){
			for (int i=2;i<n;i++){
				ll tmp=((arr[i+1]-arr[i]+arr[i+1]-arr[1])*(i))/2;
				if (tmp<=m){
					ans=i+1;
				}
			}
		}else{
			for (int i=1;i<=n/2;i++){
				swap(arr[i],arr[n-i+1]);
			}
			for (int i=2;i<n;i++){
				ll tmp=((arr[i+1]-arr[i]+arr[i+1]-arr[1])*(i))/2;
				if (tmp<=m){
					ans=i+1;
				}
			}
		}
		cout << ans;
		return 0;
	}
	sort(arr+1,arr+n+1);
	r=n;
	while (l<=r){
		mid=(l+r)/2;
		if (check(mid)){
			l=mid+1;
			ans=max(mid,ans);
		}else{
			r=mid-1;
		}
	}
	cout << ans;
	return 0;
}
