#include<bits/stdc++.h>
using namespace std;
int n;
long long a[500010],sum[500010],m;
bool chk(int i,int num){
	return num*a[i]-sum[i]+sum[i-num]<=m;
}
int ef(int i){
	int l=1,r=i,ans=0;
	while(l<=r){
		int mid=l+r>>1;
		if(chk(i,mid)){
			ans=mid;
			l=mid+1;
		}else{
			r=mid-1;
		}
	}
	return ans;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		ans=max(ans,ef(i));
	}
	cout<<ans;
}