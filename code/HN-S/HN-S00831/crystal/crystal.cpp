#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pr pair<int,int>
#define fi first
#define se second
int a[500005];
int n;
int check(int m){
	int s=0;
	for(int i=1;i<m;i++)
		s+=a[m]-a[i];
	int mi=s;
	for(int i=m+1;i<=n;i++){
		s+=a[i-m]-m*a[i-1]+(m-1)*a[i];
		mi=min(mi, s);
	} 
	return mi;
}
signed main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	std::ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1, a+n+1);
	int l=1, r=n, ans=0;
	while(l<=r){
		int mid=l+r>>1;
		if(check(mid)<=m) ans=mid, l=mid+1;
		else r=mid-1; 
	}
	cout<<ans;
	return 0;
} 
/*
首先发现答案具有单调性
你需要增加的数越多你的要的m也越多
于是考虑二分答案
接下来就是check怎么写
就是\sum_{l=i-m+1}^i a_i-a_i-a_l 
*/ 
