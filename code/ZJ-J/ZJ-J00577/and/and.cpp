#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll a[200010];
ll ans=0;
int n,m;
void dfs(int i,ll s,int p){
	if(i>n){
		if(p==m){
			ans=max(ans,s);
		}
		return;
	}
	dfs(i+1,s&a[i],p+1);
	dfs(i+1,s,p);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	} 
	sort(a+1,a+n+1);
	if(n<=20){
		ll k=1;
		for(int i=1;i<=30;i++){
			k*=2;
		}
		dfs(1,k-1,0);
		cout<<ans<<endl;
		return 0; 
	}//25pts
	if(n<=2000){
		if(m==1){
			cout<<a[n];
			return 0;
		}//30pts
		if(m==n){
			ll sum=a[1];
			for(int i=2;i<=n;i++){
				sum=sum&a[i];
			}
			cout<<sum;
			return 0; 
		}//35pts
		if(m==2){
			ll ans=-1;
			for(int i=1;i<=n-1;i++){
				for(int j=i+1;j<=n;j++){
					ans=max(ans,a[i]&a[j]);
				}
			}
			cout<<ans<<endl;
			return 0; 
		}//50pts 
		if(m==n-1){
			if(a[1]==0){
				int sum=a[2];
				for(int i=3;i<=n;i++){
					sum=sum&a[i];
				}
				cout<<sum<<endl;
				return 0;
			}
			else{
				ll sum=a[1];
				for(int i=2;i<=n;i++){
					sum=sum&a[i];
				}
				ll ans=-1;
				for(int i=1;i<=n;i++){
					ll s=sum&~(a[i]);
					ans=max(s,ans); 
				} 
				cout<<ans<<endl;
				return 0; 
			}
		}//60pts
	}
	ll sum=a[n-m+1];
	cout<<sum<<endl; 
	for(int i=n-m+2;i<=n;i++){
		sum=sum&a[i];
		cout<<a[i]<<endl; 
	}
	cout<<sum;
	return 0;
	//马扁分 
}
//好心人可以送我400pts吗？ 
