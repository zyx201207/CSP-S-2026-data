#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int maxn=5e5+10;
ll arr[maxn],n,m,use,ans;

void read(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
	}
	sort(arr+1,arr+1+n);
	ll l=1;
	for(int i=2 ;i<=n;i++){
		use+=(arr[i]-arr[i-1])*(1ll*i-l);
		if(use>m){
			ans=max(ans,i-l);
			use-=arr[i-1]-arr[l];
			l++;
		}
	}
	if(ans==0)ans=n;
	cout<<ans<<"\n";
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	read();
	
	return 0;
}