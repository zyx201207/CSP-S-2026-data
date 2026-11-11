#include<bits/stdc++.h>
using namespace std;
long long arr[500005],sum[500005],ans=1;
long long n,m;
bool chak(long long mid,int y,long long x){
	//cout<<(x*(y-mid))-(sum[y-1]-sum[mid-1])<<' ';
	if((abs(x)*(y-mid))-(sum[y-1]-sum[mid-1])<=m){
		return 1;
	}
	else{
		return 0;
	}
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	sum[0]=0;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
	}
	sort(arr+1,arr+n+1);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+arr[i];
	}
	long long l=1,r,mid,ans=1,x;
	for(int i=2;i<=n;i++){
		x=arr[i];
		l=1;
		r=i;
		while(l<r){
			mid=(l+r)/2;
			if(chak(mid,i,x)){
				r=mid;
			}
			else{
				l=mid+1;
			}
		}
		//cout<<l<<' '<<r<<' '<<mid<<' '<<ans<<'\n';
		ans=max(ans,i-l+1);
	}
	cout<<ans;
} 
