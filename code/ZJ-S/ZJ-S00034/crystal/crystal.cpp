#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500005],cf[500005],minn=0x3f3f3f3f3f3f3f3f;
bool check(int num){
	int sum=0,mins=0x3f3f3f3f3f3f3f3f,cnt=0;
	for(int i=1;i<=n;i++){
		sum+=a[i];
		++cnt;
		if(cnt>num){
			sum-=a[i-num];
			--cnt;
		}
		if(cnt==num){
			mins=min(mins,a[i]*num-sum);
		}
	}
	return (mins<=m);
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		minn=min(minn,a[i]);
	}
	sort(a+1,a+n+1);
	int l=1,r=n,ans=-1;
	while(l<=r){
		int mid=(l+r)>>1;
		if(check(mid)){
			l=mid+1;
			ans=mid;
		}
		else{
			r=mid-1;
		}
	}
	cout<<ans;
	return 0;
}
