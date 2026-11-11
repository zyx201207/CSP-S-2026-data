#include<bits/stdc++.h>
using namespace std;
long long a[500005],s[500005];
int n;
long long m;
bool check(int x){
	int l=1,r=x;
	while(r<=n){
		long long sum=(x-1)*a[r]-(s[r-1]-s[l-1]);
		if(sum<=m)return 1;
		l++,r++;
	}
	return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
	int l=1,r=n,ans;
	while(l<=r){
		int mid=(l+r)/2;
		if(check(mid)){ 
			ans=mid;
			l=mid+1;
		}
		else r=mid-1;
	}
	cout<<ans;
	return 0;
} 
