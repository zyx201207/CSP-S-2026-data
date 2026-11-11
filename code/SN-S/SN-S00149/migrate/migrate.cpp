#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[500005],n,m,num;
int dfs(int l,int r,int ln){
	if(l==r){
		return ln;
	}
	int i=l;
	while(i<r&&a[i+1]-a[l]<=m){
		i++;	
	}
	return dfs(i,r,ln+1);
}
void dfs1(int l,int r,int ln,int k){
	if(l==r){
		num+=(ln==k);
		return ;
	}
	int i=l;
	while(i<r&&a[i+1]-a[l]<=m){
		i++;
		dfs1(i,r,ln+1,k);
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int C,T;cin>>C>>T;
	while(T--){
		cin>>n>>m;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				num=0;
				int mn=dfs(i,j,0);
				dfs1(i,j,0,mn);
				if(num==2){
					ans++;
				}
			}
		}
		cout<<ans<<"\n";
	}
} 
