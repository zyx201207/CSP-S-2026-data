#include <bits/stdc++.h>
#define ll long long
using namespace std;
//易想到二分
//要在O(n)的复杂度下写出check
//遍历起点
//前缀和？
//可以可以qwq 
ll s[500010]; 
ll a[500010];
int n,m;
bool check(int x){
	ll sum=1e18;
	for(int i=1;i+x-1<=n;i++){
		int j=i+x-1;
		sum=min(sum,s[j]-s[i-1]-(a[j]-a[i-1])*(i-1));
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
	sort(a+1,a+n+1);
	s[1]=0;
	for(int i=2;i<=n;i++){
		s[i]=s[i-1]+(i-1)*(a[i]-a[i-1]);
	}
	int l=1,r=n,mid,ans;
	while(l<=r){
		mid=(l+r)>>1;
		if(check(mid)){
			l=mid+1;
			ans=mid;
		}
		else{
			r=mid-1;
		}
	}
	cout<<ans<<endl;
	return 0; 
}
//大洋里全国
//好心人能送我400pts吗？ 
