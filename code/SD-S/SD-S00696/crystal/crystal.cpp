#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+3;
int arr[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>arr[i];
	sort(arr+1,arr+n+1,greater<int>());
	int num=0,ans=1;
	for(int i=1,j=0;i<=n;i++){
		num-=(arr[i-1]-arr[i])*(j-i+1);
		while(j+1<=n&&num+arr[i]-arr[j+1]<=m)
			{num+=arr[i]-arr[j+1];j++;}
		ans=max(ans,j-i+1);
	}
	cout<<ans<<"\n";
	return 0;
}

