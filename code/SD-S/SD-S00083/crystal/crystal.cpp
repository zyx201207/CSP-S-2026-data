#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int maxn=5e5+10;
int n,m,a[maxn],sum[maxn];
bool check(int x){
	for(int i=1;i<=n-x+1;i++){
		if(x*a[i+x-1]-(sum[i+x-1]-sum[i-1])<=m)return 1;
	}
	return 0;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	int l=1,r=n+1;
	while(l<r){
		int mid=l+r>>1;
		if(check(mid)){
			l=mid;if(r==l+1)break;
		}
		else{
			r=mid;
		}
	}
	cout<<l;
	return 0;
}
