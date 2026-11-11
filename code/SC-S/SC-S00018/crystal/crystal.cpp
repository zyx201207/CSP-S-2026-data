#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500000];
int main(){
	freopen("r","crystal.in",stdin);
	freopen("w","crystal.out",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	long long ans=-0x3f3f3f3f3f3f3f;
	for(int i=n;i>=1;i--){
		long long x=m,cnt=1;
		while(x>0&&i-cnt>=1){
			x-=a[i]-a[i-cnt];
			cnt++;
		}
		ans=max(ans,cnt);
	}
	cout<<ans;
	return 0;
} 