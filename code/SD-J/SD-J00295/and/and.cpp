#include<bits/stdc++.h>
using namespace std;
long long a[200086],ma,cnt,vis[10086];
int n,m;
void dfs(int x){
	if(x>m){
		bool t=0;
		for(int i=1;i<=n;i++){
			if(vis[i]==1){
				if(t==0){
					cnt=a[i];
					t=1;
				}
				else cnt=(cnt&a[i]);
			}
		}
		ma=max(ma,cnt);
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==0){
			vis[i]=1;
			dfs(x+1);
			vis[i]=0;
		}
	}
}
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
	dfs(1);
	cout<<ma;
	return 0;
}
