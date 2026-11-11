#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
int n,m,a[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	int sum=0,ans=0;
	for(int i=1,j=1;i<=n;i++){
		sum+=(a[i]-a[i-1])*(i-1-j+1);
		while(j<=i&&sum>m) sum-=(a[i]-a[j]),j++;		
		if(sum<=m) ans=max(ans,i-j+1);
	}
	cout<<ans;
	return 0;
}
/*
考虑对每个数 x，找到 <=x 且 ∑(y-x)<=m 的最多 y 的个数。
先排序，考虑直接用双指针维护，
右指针向右扩展 1 左指针随之扩张直到区间和 <=m。
时间复杂度 O(n\log n)。 
*/