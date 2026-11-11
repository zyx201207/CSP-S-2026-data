#include<bits/stdc++.h>
using namespace std;
int a[200005];
bool f[200005][35];
bool vis[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		for(int j=0;j<=32;j++){
			if(a[i]&1){
				f[i][j]=1;
			}
			a[i]>>=1;
		}
	}
	int ans=0;
	for(int j=32;j>=0;j--){
		int sum=0;
		for(int i=1;i<=n;i++){
			if(f[i][j]==1&&vis[i]==0){
				sum++;
			}
		}
		if(sum<m){
			continue;
		}
		ans+=(1<<j);
		for(int i=1;i<=n;i++){
			if(f[i][j]==0&&vis[i]==0){
				vis[i]=1;
			}
		}
	}
	cout<<ans;
	return 0;
}