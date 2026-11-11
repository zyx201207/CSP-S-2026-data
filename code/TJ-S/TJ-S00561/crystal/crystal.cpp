#include<bits/stdc++.h>
using namespace std;
int n;
long long arr[500005];
long long farr[500005];
long long m,ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
	}
	sort(arr+1,arr+n+1);
	for(int i=1;i<=n;i++){
		farr[i]=farr[i-1]+arr[i];
	}
	for(long long i=2;i<=n;i++){
		long long l=1;
		long long r=i;
		while(l<r){
			long long mid=(r+l)/2;
			long long neds=(arr[i]*(i-mid)-(farr[i-1]-farr[mid-1]));
			if(neds<=m){
				ans=max((i-mid+1),ans);
				r=mid;
			}else{
				l=mid+1;
			}
		}
	}
	cout<<ans;
	return 0;
} 
