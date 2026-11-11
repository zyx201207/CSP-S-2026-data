#include <bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500050];
bool check(long long x){
	long long cnt=0;
	for(int i=1;i<=n;i++){
		if(a[i]<=x){
			cnt+=x-a[i];
		}else{
			continue;
		}
	}
	if(cnt<=m)return true;
	else return false;
}
int main(){
	freopen("crystal.in","r",stdin);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	long long l=-1e12,r=1e12,mid;
	while(l<=r){
		mid=(l+r)/2;
		if(check(mid)){
			l=mid+1;
		}else{
			r=mid-1;
		}
	}
	long long ans=0;
	for(int i=1;i<=n;i++){
		if(mid>=a[i]){
			ans++;
		}
	}
	freopen("crystal.out","w",stdout);
	cout<<ans;
	return 0;
}
