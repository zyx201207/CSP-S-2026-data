#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define N 500005

int n,m,ans;
int a[N],sum[N];

signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	ans=1;
	for(int i=n;i>=1;i--){//枚举中间的位置
		int l=1,r=i,id=-1;
		while(l<=r){
			int mid=(l+r)/2;
			if(a[i]*(i-mid+1)-(sum[i]-sum[mid-1])<=m){
				id=mid;
				r=mid-1;
			}
			else{
				l=mid+1;
			}
		}
		if(id!=-1)
			ans=max(ans,i-id+1);
	}
	cout<<ans;
	return 0;
}
/*
5 8 
-3 -1 2 2 7

*/