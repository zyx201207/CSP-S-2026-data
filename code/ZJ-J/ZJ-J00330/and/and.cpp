#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int N=1e6+10;
int n,m;
int a[N];
int ans=0;
int vis[N];
void dfs(int d,int sum){
	if(d==m){
		ans=max(ans,sum);
		return;
	}
	for(int i=1;i<=n;i++){
		if(sum==0){
			vis[i]=1;
			dfs(d+1,a[i]);
			vis[i]=0;
		}
		else if(vis[i]==0){
			vis[i]=1;
			dfs(d+1,sum&a[i]);
			vis[i]=0;
		}
	}
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	
	if(n==m){
		int ans=0;
		for(int i=1;i<=n;i++){
			int k; cin>>k;
			if(i==1) ans=k;
			else ans&=k;
		}
		cout<<ans;
		return 0;
	}
	if(m==1){
		int ans=0;
		for(int i=1;i<=n;i++){
			int k; cin>>k;
			ans=max(ans,k);
		}
		cout<<ans;
		return 0;
	}
//	if(m==2){
//		int ans=0;
//		for(int i=1;i<=n;i++) cin>>a[i];
//		for(int i=1;i<=n;i++){
//			for(int j=i+1;j<=n;j++){
//				ans=max(ans,a[i]&a[j]);
//			}
//		}
//		cout<<ans;
//		return 0;
//	}
//	if(n<=20){
//		for(int i=1;i<=n;i++) cin>>a[i];	
//		dfs(0,0);
//		cout<<ans;
//		return 0;
//	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int ans=0;
	sort(a+1,a+1+n);
	for(int i=1;i<n;i++){
		if(a[i]==a[i+1]) ans=a[i];
	}
	int sum=0;
	for(int i=n;i>=n-m+1;i--){
		if(i==n) sum=a[i];
		else sum&=a[i];
	}
	cout<<max(sum,ans);
	return 0;
}