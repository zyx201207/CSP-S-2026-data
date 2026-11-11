#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=5e5+5;
int n,ans;
ll m,a[N],pre[N],num[N];
int main(){
	cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)pre[i]=pre[i-1]+a[i];
	int l=1,r=1;
	ll sum=0;
	while(r<n){
		while(r<n&&sum+(r+1-l)*(a[r+1]-a[r])<=m){
			sum+=(r+1-l)*(a[r+1]-a[r]);
			r++;
		}
		ans=max(ans,r-l+1);
		sum-=a[r]-a[l];
		l++;
	}
	cout<<ans;
	return 0;
}
