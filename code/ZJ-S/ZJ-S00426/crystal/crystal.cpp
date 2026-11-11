#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5E5+5;
int n,a[N];
int pre[N],m;
bool check(int mid){
	for(int i=1;i+mid-1<=n;i++){
		if(a[i+mid-1]*mid - (pre[i+mid-1] - pre[i-1]) <=m)return true;
	}return false;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1 ,a+n+1);
	for(int i=1;i<=n;i++)
		pre[i] = pre[i-1] + a[i];
	
	int l=1,r=n,ans=0;
	while(l<=r){
		int mid=l+r>>1;
		if(check(mid))ans=mid,l=mid+1;
		else r=mid-1;
	}cout<<ans;
	return 0;
}