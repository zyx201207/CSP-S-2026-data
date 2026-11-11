#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+1e4;
long long a[maxn],sum[maxn],m;
int n,num=0;
long long check(int l,int r,long long mid){
	num=mid-l+1; 
	return a[mid]*(mid-l+1)-(sum[mid]-sum[l-1]);
}
int find(int startl,int startr){
	int l=startl,r=startr,ans=0;
	while(l<=r){
		int mid=l+r>>1;
		if(check(startl,startr,mid)<=m){
			l++;
			ans=max(ans,num);
		}
		else{
			r--;
		}
	}
	return ans;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	int ans=0;
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	cout<<find(1,n);
	return 0; 
} 
