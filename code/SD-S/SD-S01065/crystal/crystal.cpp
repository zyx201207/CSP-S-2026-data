#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+5;
int n;
ll m,a[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i)cin>>a[i];
	sort(a+1,a+n+1);
	int ans=0,r=n;
	ll sum=0;
	while(r-1>0&&sum+a[n]-a[r-1]<=m) sum+=a[n]-a[--r];
	for(int i=n-1;i>=1;--i){
		if(r>i) r=i;
		sum-=(i-r+1)*(a[i+1]-a[i]);
		while(r-1>0&&sum+a[i]-a[r-1]<=m) sum+=a[i]-a[--r];
		ans=max(ans,i-r+1);
	}
	cout<<ans;
	return 0;
} 
