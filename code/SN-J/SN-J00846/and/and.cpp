#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int a[200004];
//int maxx=-1;
//void dfs(int cnt,int ans,int l){
//	if(cnt==m+1){
//		maxx=max(ans,maxx);
//		cout<<endl;
//		return;
//	}
////	cout<<1;
//	for(int i=l+1;(n-i)>=(m-cnt-1);i++){
//		int x=ans&a[i];
//		dfs(cnt+1,x,i);
//		cout<<i<<" ";
//	}
//}
signed main(){
	freopen("and.in","r",stdout);
	freopen("and.out","w",stdout);
//许子衿 SN-J00846 西安翱翔中学
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
//	for(int i=1;i<=n-m+1;i++){
//		dfs(1,a[i],i);
//	}
//	cout<<maxx;
	if(m==1){
		sort(a+1,a+n+1);
		cout<<a[n];
	}else if(m==n){
		int ans=1;
		for(int i=1;i<=n;i++){
			ans&=a[i];
		}
		cout<<ans;
	}else if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(j!=i){
					ans=a[i]&a[j];
				}
			}
		}
		cout<<ans;
	}else if(m==n-1){
		int maxx=-1;
		for(int i=1;i<=n;i++){
			int ans=1;
			for(int j=1;j<=n;j++){
				if(j!=i){
					ans&=a[j];
				}
			}
			maxx=max(maxx,ans);
		}
		cout<<maxx;
	}else{
		cout<<0;
	}
	return 0;
}
