#include<bits/stdc++.h>
using namespace std;
int n;
long long m;
long long a[500010];
long long b[500010];
int sum(int x,int y){
	return b[y]-b[x-1];
} 
//区间[l,i-1]所需代价为
//ai*(i-l)-sum[l,i-1] 
bool check(int len){
	for(int i=len+1;i<=n;i++){
		if(a[i]*len-sum(i-len,i-1)<=m) return 1;
	}
	return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) b[i]=b[i-1]+a[i];
	int ans=0;
	int l=0,r=n;
	while(l<=r){
		int mid=(l+r)/2;
		if(check(mid)) l=mid+1,ans=mid;
		else r=mid-1;
	}
	cout<<ans+1;
}   
