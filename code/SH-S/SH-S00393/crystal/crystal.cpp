#include<bits/stdc++.h>
using namespace std;
long long n,a[500005],m;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	if(n<=5000){
		long long ans=0;
		for(int i=1;i<=n;i++){
			long long cnt=1,m1=m;
			for(int j=i-1;j>=1;j--){
				if(a[i]-a[j]<=m1){
					m1-=a[i]-a[j];
					cnt++;
				}
				else break;
			}
			ans=max(ans,cnt);
		}
		cout<<ans;
		return 0;
	}
	bool ts=1;
	long long c=a[2]-a[1];
	for(int i=3;i<=n;i++){
		if(a[i]-a[i-1]!=c){
			ts=0;
			break;
		}
	}
	if(ts){
		long long ans=1;
		for(int i=n-1;i>=1;i--){
			if(a[n]-a[i]<=m){
				m-=a[n]-a[i];
				ans++;
			}
		}
		cout<<ans;
		return 0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
