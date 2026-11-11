#include<bits/stdc++.h>
using namespace std;
long long arr[500025];
int n;
long long m;
long long sum[500025];
bool check(int num){
	int l=1,r=num;
	while(r<=n){
		if((num*arr[r])-(sum[r]-sum[l-1])<=m){
			return true;
		}
		l++,r++;
	} 
	return false;
}
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
	sort(arr+1,arr+1+n);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+arr[i];
	}
	int l=1,r=n;
	int ans=0;
	while(l<r){
		int mid=(l+r)>>1;
		if(check(mid)){
			ans=mid;
			l=mid+1;
		}else{
			r=mid-1;
		}
	}
	for(int i=ans;i>=ans-5&&i>=1;i--){
		if(!check(i)){
			ans=i;
		}
	}
	for(int i=ans;i<=ans+5&&i<=n;i++){
		if(check(i)){
			ans=i;
		}
	}
	cout<<ans<<"\n";
	return 0;
}
