#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n=0,m=0,a[500005],sum=0,ans=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a,a+n+1);
	for(ll i=1;i<=n;i++){
		for(ll j=i-1;j>=1;j--){
			sum+=a[i]-a[j];
			if(sum>m){
				sum=0;
				ans=max(ans,i-j+1);
				break;
			}
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
	
