#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10,INF=4e18;
int n,a[N],m,ans;
bool check(int len){
	int sum=0,mx=-INF;
	for(int i=1;i<=len;i++){
		sum+=a[i];
		mx=a[len];
	}
	if(mx*len<=sum+m){//可以通过至多m次操作使得合法区间长度为len 
		return 1;
	}
	for(int i=2;i<=n-len+1;i++){
		sum-=a[i-1];
		sum+=a[i];
		mx=a[i+len-1];
		if(mx*len<=sum+m){
			return 1;
		}
	} 
	return 0;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	int l=1,r=n;
	while(l<=r){
		int mid=(l+r)>>1ll;
		if(check(mid)){
			ans=mid;
			l=mid+1;
		}else{
			r=mid-1;
		}
	}
	cout<<ans;
	return 0;
}

