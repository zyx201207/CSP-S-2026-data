#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
int c,n,m,d,q,a[N],k[N],u[510][20010],v[510][20010],mp[N],ans;
bool check(int x,int y){
	return 1<=x&&x<=n&&1<=y&&y<=k[x];
}
void dfs(int x,int y,int Y,int sum){
	if(u[x][y]==Y){
		sum+=v[x][y];
		sum+=a[u[x][y]];
		ans=min(ans,sum);
		return ;
	}
	if(check(x,y+1)){
		if(u[x][y]==Y){
			sum+=v[x][y];
			sum+=a[u[x][y]];
			ans=min(sum,ans);
			return ;
		}
		dfs(x,y+1,Y,sum);
		for(int i=x+1;i<=n;i++){
			for(int j=1;j<=k[i];j++){
				if(u[i][j]==u[x][y]){
					sum+=v[x][y];
					sum+=v[i][j];
					dfs(i,j,Y,sum);
				}
			}
		}
	}else{
		if(x==n) return ;
		if(y==k[x]){
			for(int i=x+1;i<=n;i++){
				for(int j=1;j<=k[i];j++){
					if(u[i][j]==u[x][y]){
						sum+=v[x][y];
						dfs(i,j,Y,sum);
					}
				}
			}
		}
	}
	 
} 
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>u[i][j]>>v[i][j];
			mp[u[i][j]]++;
		}
	}
	while(q--){
		int x,y,s=0,X=1,Y=1,l=1,r=1;
		ans=INT_MAX;
		cin>>x>>y;
		if(x>=y){
			swap(x,y);
		}
		X=x;
		Y=y;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=k[i];j++){
				if(u[i][j]==y){
					
				}else if(u[i][j]==x){
					dfs(i,j,Y,a[x]+v[i][j]);
				}
			}
		}
		cout<<ans<<endl;
	}
	
	return 0;
}
