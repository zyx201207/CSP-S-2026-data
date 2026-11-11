#include<iostream>
#include<cstdio>
using namespace std;
int n,m;
long long a[200005];
long long maxx=0;
//void dfs(long long ans,int cnt){
//	if(cnt==m+1){
//		maxx=max(ans,maxx);
//	}
//	for(int i=1;i<=n;i++){
//		dfs(ans&a[i],cnt+1);
//		dfs(ans,cnt);		
//	}
//}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	long long mx=0;
	if(m==1){
		for(int i=1;i<=n;i++){
			mx=max(mx,a[i]);
		}
		cout<<mx;
		return 0;
	}
	else if(m==n){
		long long anss=a[1];
		for(int i=2;i<=n;i++){
			anss=anss&a[i];
		}
		cout<<anss;
		return 0;
	}
	else if(m==2){
		long long mxx=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				mxx=max(mxx,a[i]&a[j]);
			}
		}
		cout<<mxx;
		return 0;
	}
	else{
		long long maxxx=0;
		for(int i=1;i<=n;i++){
			maxxx=max(maxxx,a[i]);
		}
		cout<<maxxx;
		return 0;
	}
//	else if(m==n-1){
//		for(int i=1;i<=n;i++){
//			
//		}
//	}
//	else{
//		for(int i=1;i<=n;i++){
//			dfs(0,0);
//			vis[a[i]]=1;
//			dfs(a[i],1);
//		}
//		
//		cout<<maxx;
//	}

	return 0;
} 
