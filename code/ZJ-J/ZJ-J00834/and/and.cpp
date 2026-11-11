#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[200005];
ll ans[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	
	
	if(n<=20){
		ll ans=-1;
		for(int i=1;i<=1<<n;i++){
			ll t=i,cnt=0,s;
			for(int j=1;j<=n;j++){
				if(t&1){
					cnt++;
					if(cnt==1) s=a[j];
					else s=s&a[j];
				}
				t/=2;
			}
			if(cnt==m){
				ans=max(ans,s);
			}
		}
		cout<<ans;
		return 0;
	}
	if(m==1){
		sort(a+1,a+n+1);
		cout<<a[n];
		return 0;
	}
	if(m==n){
		ll s=a[1];
		for(int i=2;i<=n;i++){
			s&=a[i];
		}
		cout<<s;
		return 0;
	}
	if(n<=2000&&m==2){
		ll ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				ans=max(ans,a[i]&a[j]);
			}
		}
		cout<<ans;
		return 0;
	}
	bool flag=1;
	for(int i=1;i<=n;i++){
		ll s=a[i]+1;
		while(!(s&1)){
			s/=2;
		}
		if(s!=1) flag=0;
	}
	if(flag){
		sort(a+1,a+n+1);
		cout<<a[n-m+1];
		return 0;
	}
	return 0;
}
