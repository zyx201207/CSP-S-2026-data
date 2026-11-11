#include<bits/stdc++.h>
using namespace std;
long long int n,m,a[500010],ans;
long long int sum[500010];
bool check(long long int mid){
	for(int i=mid;i<=n;i++){
		long long int num=sum[i]-sum[i-mid];
		num=a[i]*mid-num;
		if(num<=m)return 1;
	}
	return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	stable_sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
	int l=1,r=n;
	while(l<=r){
		long long int mid=(l+r)/2;
		if(check(mid)){
			l=mid+1;
			ans=max(ans,mid);
		}
		else{
			r=mid-1;
		}
	}
	cout<<ans;
	
	return 0;
}