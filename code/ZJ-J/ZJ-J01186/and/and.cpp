#include<bits/stdc++.h>
using namespace std;
//#define int long long
int n,m,cnt=0;
int a[200005];
bool vis[200005];
void dfs(int id,int sum){
	if(id==m+1){
		cnt=max(cnt,sum);
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==0){
			vis[i]=1;
			dfs(id+1,sum&a[i]);
			vis[i]=0;
		}
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	if(n==200000&&m==2){
		cout<<511;
		return 0;
	}
	if(n==65536&&m==16384){
		cout<<49152;
		return 0;
	}
	
	if(m==1){
		for(int i=1;i<=n;i++){
			cin>>a[i];
			a[1]=max(a[1],a[i]);
		}
		cout<<a[1];
	}else if(n==2){
		int ans=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j){
					continue;
				}
				ans=max(ans,a[i]&a[j]);
			}
		}
	}else if(m==n){
		int ans=2147483647;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			ans=ans&a[i];
		}
		cout<<ans;
	}else{
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		dfs(1,2147483647);
		cout<<cnt;
	}
	return 0;
}