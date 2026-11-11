#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[500005],now,ans=1;
bool aii=true,dc=true;
signed main(){
	// maybe 75 pts
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i){
			aii=false;
		}
		if(i>=3&&a[i]-a[i-1]!=a[i-1]-a[i-2]){
			dc=false;
		}
	}
	if(aii){
		for(int i=1;i<n;i++){
			now+=(a[i+1]-a[i])*i;
			if(now<=m){
				ans++;
			}else{
				break;
			}
		}
		cout<<ans<<endl;
		return 0;
	}
	if(dc){
		for(int i=1;i<n;i++){
			now+=(a[i+1]-a[i])*i;
			if(now<=m){
				ans++;
			}else{
				break;
			}
		}
		cout<<ans<<endl;
		return 0;
	}
	sort(a+1,a+n+1);
	for(int i=1;i<n;i++){
		now=0;
		int tans=1;
		for(int j=i-1;j>=1;j--){
			now+=(a[i]-a[j]);
			if(now<=m){
				tans++;
			}else{
				break;
			}
		}
		ans=max(ans,tans);
	}
	cout<<ans<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}