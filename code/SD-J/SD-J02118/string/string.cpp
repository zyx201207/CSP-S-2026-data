#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct myst{
	ll nums,nump;
	char namee;
}arr[200010];
ll ans,n;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>arr[i].nums>>arr[i].namee;
		arr[i].nump=arr[i].nums;
	}
	ll l=1,r=n;
	while(l<r){
		ll stempp=min(arr[l].nump,arr[r].nump);
		if(arr[l].namee!=arr[r].namee){
			ans+=stempp;
		}
		arr[l].nump-=stempp;
		arr[r].nump-=stempp;
		if(arr[l].nump==0)l++;
		if(arr[r].nump==0)r--;
	}
	cout<<ans;
	return 0;
}
