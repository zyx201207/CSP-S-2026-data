#include<bits/stdc++.h>
using namespace std;
#define int long long
const int Maxn=5e5,Maxm=10e18;
int n,m;
bool cmp(int x,int y){
	return x>y;
}
int sum[Maxn],a[Maxn];
bool check(int i){
	int l=1,r=i;
	for(;r<=n;r++,l++){
		int res=sum[r]-sum[l-1];
//		cout<<res<<" "<<a[l]<<" ";
		if(a[l]*i-res<=m){
			return 1;
		}
	}
	return 0;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	int flag=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	int l=1,r=n,mid;
	while(l<=r){
		mid=(l+r)>>1;
		if(check(mid)){
			l=mid+1;
		}else{
			r=mid-1;
		}
	}
	cout<<l-1;
	return 0;
} 
/*
5 5
1 2 4 8 9
*/
