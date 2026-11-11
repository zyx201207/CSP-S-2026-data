#include <bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long arr[N];
long long brr[N];
long long crr[N];
long long n,m;
bool check(long long x){
	long long cnt=0;
	for(int i=1;i<=n;i++){
		if(i<=x){
			cnt+=crr[x]-crr[i];
		}else{
			if(cnt<=m){
				return 1;
			}
			cnt=cnt+(crr[i]-crr[i-1])*(x-1)-(crr[i-1]-crr[i-x]);
		}
	}
	if(cnt<=m){
		return 1;
	}
	return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >>n>>m;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
	}
	sort(arr+1,arr+1+n);
	brr[1]=0;
	for(int i=2;i<=n;i++){
		brr[i]=arr[i]-arr[i-1];
		crr[i]+=brr[i]+crr[i-1];
	}
	long long l=0,r=n;
	long long ans=0;
	while(l<=r){
		long long mid=(l+r)/2;
		if(check(mid)){
			l=mid+1;
			ans=l-1;
		}else{
			r=mid-1;
		}
	}
	cout<<ans;
	return 0;
}
