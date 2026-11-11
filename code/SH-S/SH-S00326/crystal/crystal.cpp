#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500005];
long long ans; 
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=n;i>=1;i--){
		long long sum=0;
		for(int j=i;j>=1;j--){
			if(sum+a[i]-a[j]>m){
				ans=max(ans,1ll*(i-j));
				break;
			}
			else{
				sum+=a[i]-a[j];
			}
			if(j==1){
				ans=max(ans,1ll*i);
			}
		}
	}
	cout<<ans;
	return 0;
}
