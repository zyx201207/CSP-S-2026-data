#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int n,m,a[N],s[N];
inline bool check(int mid){//判断用 mid 个能不能合成 
	//贪心去选择基数
	//类似于滑动窗口去维护 
	int sum=0;
	for(int i=1;i<=n;i++){
		if(i<=mid) sum+=a[mid]-a[i];
		else{
			if(sum<=m) return 1;
			sum-=a[i-1]-a[i-mid];
			sum+=mid*(a[i]-a[i-1]);
		}
	}
	return sum<=m;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	int l=1,r=n;
	while(l<r){
		int mid=l+r+1>>1;
		if(check(mid)) l=mid;
		else r=mid-1;
	}
	cout<<l;
	return 0;
}
