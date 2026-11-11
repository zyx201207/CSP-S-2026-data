#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int ans;
int a[500010];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	if(n<=5000){
		for(int i=1;i<=n;i++){
			int sum=0;
			int x=m;
			for(int j=i;j>=1;j--){
				if(x>=a[i]-a[j]){
					x-=(a[i]-a[j]);
					sum++;
				}
			}
			ans=max(ans,sum);
		}
	}
	else{
		for(int i=1;i<n;i++){
			if(m>=a[i+1]-a[i]){
				m-=i*(a[i+1]-a[i]);
				ans++;
			}
		}	
	}
	cout<<ans;
	return 0;
}
