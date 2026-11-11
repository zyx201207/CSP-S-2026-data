#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#include<map>
#include<queue>
#define int unsigned long long
using namespace std;
//一定要去注释
//一定要去注释
//一定要去注释
//一定要去注释
//一定要去注释 
int f[5010][5010];
int a[5010];
int n,d;
void dfs(int l,int r){
	if(f[l][r]==-1)return;
	for(int i=l+1;i<=r;i++){
		if(f[l][i]==-1&&a[r]-a[i]<=d){
			f[l][r]++;
		}
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int c,t;cin>>c>>t;
	while(t--){
		cin>>n>>d;
		memset(f,0,sizeof f);
		int idx=0;
		for(int i=1;i<=n;i++){
			long long x;cin>>x;
			if(i==1&&x<0)idx=x-1;
			a[i]=x-idx;
		}
		
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(a[j]-a[i]<=d)f[i][j]=-1;
			} 
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				dfs(i,j);
			}
		}
		
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
//				cout<<f[i][j]<<' ';
				if(f[i][j]==2)ans++;
			}
//			cout<<endl;
		}
			
				
		cout<<ans<<endl;
	}
	return 0;
}
//一定要去注释
//一定要去注释
//一定要去注释
//一定要去注释
//一定要去注释

