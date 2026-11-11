#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(n==1){
		cout<<1;
		return 0;
	}
	sort(a+1,a+n+1);
	for(int i=n;i>=1;i--){
		long long sum=0,cnt=1;
		for(int j=i-1;j>=1;j--){
			if((sum+a[i]-a[j])<=m){
				sum=sum+a[i]-a[j];
				cnt++;
			}else break;
		}
		ans=max(ans,cnt);
	}
	cout<<ans;
	return 0;
}
