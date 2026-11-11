#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int a[N],b[N];int n,m;
int c(int x){
	int sum=0;
	for(int i=1;i<=x;i++){
		sum+=a[i];
	}
	int minn=a[x]*x-sum;
	for(int i=x+1;i<=n;i++){
		sum-=a[i-x];
		sum+=a[i];
		minn=min(minn,a[i]*x-sum);
	}
	return minn;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int l=1,r=n;
	while(l<=r){
		int mid=l+r>>1;
		if(c(mid)<=m){
			l=mid+1;
		}else{
			r=mid-1;
		}
	}
	cout<<r;
	return 0;
}
