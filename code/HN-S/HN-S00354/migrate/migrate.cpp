#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,x[20005],dp[5005][5005],ans;
long long mp[1005][10005][15];
void dfs(int u,int h,int k){
	mp[k][u][h]++;
	for(int i=u+1;i<=n;i++){
		if(x[i]-x[u]<=d){
			dfs(i,h+1,k);
		}else return ;
	}
}
long long dfs2(int a,int b,int h){
	if(h==0&&a==b){
		return 1;
	}
	if(h<=0||a>=b)return 0;
	long long ans=0;
	for(int i=b;i>=a+1;i--){
		if(x[i]-x[a]<=d){
			int q2=dfs2(i,b,h-1);
			ans+=q2;
			if(q2>=3)return 3;
		}
	}
	return ans;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		ans=0;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		} 
		if(n<=9){
			for(int i=1;i<=n;i++){
				for(int j=i+2;j<=n;j++){
					for(int e2=1;e2<=n-1;e2++){
						mp[i][j][e2]=0;
					}
				}
			}
			for(int i=1;i<=n;i++){
				dfs(i,0,i);
			}
			for(int i=1;i<=n;i++){
				for(int j=i+2;j<=n;j++){
					for(int e2=1;e2<=n-1;e2++){
						//cout<<i<<j<<e2<<mp[i][j][e2]<<'\n';
						if(mp[i][j][e2]==2){
							ans++;
							break;
						}else if(mp[i][j][e2]!=0){
							break;
						}
					}
				}
			}
			cout<<ans<<'\n';
			continue;
		}
		for(int i=1;i<=n;i++){
			for(int j=i+3;j<=n;j++){
				int d=0,f=i;
				for(int e=i+1;e<=j;e++){
					//cout<<x[e]-x[f]<<x[e+1]-x[f]<<'\n';
					if(x[e]-x[f]<=d&&x[e+1]-x[f]>d){
						d++;
						f=e;
					}
					else if(x[e]-x[f]<=d&&e==j){
						d++;
						f=e;
					}
				}
				if(f==j){
					if(dfs2(i,j,d)==2)ans++;
				}else break;
			}
		}
		cout<<ans<<'\n';
	}
	return 0; 
}
