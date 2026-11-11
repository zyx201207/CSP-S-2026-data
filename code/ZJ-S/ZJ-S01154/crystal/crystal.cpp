#include<bits/stdc++.h>
using namespace std;
long long a[500005];
long long n,m;
map<int,long long> mp;
bool cmp(int x){
	for(int i=1;i<=n;i++){
		long long l=1,r=i;
		while(l<r){
			long long mid=(l+r)/2;
			if(mp[i]-mp[mid]<=m)r=mid;
			else l=mid+1;
		}
		if(i-l+1>=x)return 1;
	}
	return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)mp[i]=mp[i-1]+(i-1)*(a[i]-a[i-1]);
	long long l=1,r=n;
	while(l<r){
		long long mid=(l+r+1)/2;
		if(cmp(mid))l=mid;
		else r=mid-1;
	}
	cout<<l;
	return 0;
}