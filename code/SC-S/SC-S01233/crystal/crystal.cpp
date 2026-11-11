#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+7;
int n,m;
int a[N];
int pre[N];
int ans;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		pre[i]=pre[i-1]+a[i];
	}
	for(int l=1,r=1;r<=n;r++){
		while(a[r]*(r-l+1)-(pre[r]-pre[l-1])>m) l++;
		ans=max(ans,r-l+1);
	}
	cout<<ans;
	return 0;
}