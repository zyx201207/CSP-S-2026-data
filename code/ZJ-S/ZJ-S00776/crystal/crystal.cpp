#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,ans=1;
ll a[500005];
ll tong[100005];
ll ftong[100005];
bool flag=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	a[0]=0x3f3f3f3f;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i) flag=0;
		if(a[i]>=0) tong[a[i]]++;
		if(a[i]<0) ftong[(-a[i])]++;
	}
	sort(a+1,a+n+1);
	if(n<=5000||(a[n]<=100&&a[1]>=-100)){
		for(int i=1;i<=n;i++){
			if(a[i]==a[i-1])continue;//只选择第一个 
			ll k=m,sum=0;
			if(i==1){
				if(a[i]>=0) ans=max(ans,tong[a[i]]);
				if(a[i]<0) ans=max(ans,ftong[(-a[i])]);
			} 
			for(int j=i-1;j>=1;j--){
				if(a[i]>=0){
					if(a[i]-a[j]>k) break;
					k-=(a[i]-a[j]);
					sum+=1;
					ans=max(ans,sum+tong[a[i]]);
				}
				if(a[i]<0){
					if(a[i]-a[j]>k) break;
					k-=(a[i]-a[j]);
					sum+=1;
					ans=max(ans,sum+ftong[-a[i]]);
				}
			}
		}
		cout<<ans;
		return 0;
	}
	if(flag){
		for(int i=n;i>=1;i--){
			if((i*(i-1))/2<=m){
				cout<<i;
				return 0;
			}
		}
	}
	else{
		for(int i=1;i<=n;i++){
			if(a[i]==a[i-1])continue;//只选择第一个 
			ll k=m,sum=0;
			if(i==1){
				if(a[i]>=0) ans=max(ans,tong[a[i]]);
				if(a[i]<0) ans=max(ans,ftong[(-a[i])]);
			} 
			for(int j=i-1;j>=1;j--){
				if(a[i]>=0){
					if(a[i]-a[j]>k) break;
					k-=(a[i]-a[j]);
					sum+=1;
					ans=max(ans,sum+tong[a[i]]);
				}
				if(a[i]<0){
					if(a[i]-a[j]>k) break;
					k-=(a[i]-a[j]);
					sum+=1;
					ans=max(ans,sum+ftong[-a[i]]);
				}
			}
		}
		cout<<ans;
		return 0;
	}
	return 0;
}
