#include<bits/stdc++.h>
using namespace std;
int n;
unsigned long long m;
unsigned long long tot=0;
int ans=0;
long long a[500004];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=n;i>=1;i--){
		tot=0;
		for(int j=i-1;j>=1;j--)
		{
			tot+=a[i]-a[j];
			if(tot==m)	ans=max(ans,i-j+1);
			if(tot>m){
				ans=max(ans,i-j);
				break;
			}
			if(j==1){
				ans=max(ans,i-j+1);
				break;
			}
		}
	}
	cout<<ans;
	return 0;
}
