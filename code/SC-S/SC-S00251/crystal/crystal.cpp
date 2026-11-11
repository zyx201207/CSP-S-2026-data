#include<bits/stdc++.h>
using namespace std;
long long a[500005];
int ans;
int main(){
	freopen("crystal.in","i",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		int teamp=m,cnt=0;
		for(int j=i-1;j>=1;j--){
			if((teamp-a[i]+a[j])>=0){
				cnt++;
				teamp=teamp-a[i]+a[j];
				ans=max(ans,cnt);
			}
		}
	}
	cout<<ans+1;
	return 0;
} 