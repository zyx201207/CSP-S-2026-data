#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e3+10;
int c,T;
int n,d;
int a[N];
int jg[N][N];
bool vis[N];
void dfs(int w,int dep){
	if(n==w){
		return ;
	}
	for(int i=w+1;i<=n;i++){
		if(abs(a[i]-a[w])<=d){
			dep++;
			if(!vis[i]){
				dfs(i,dep);
				vis[i]=true;
			}
			jg[i][dep]++;
		}else{
			break;
		}
	}
	
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--){
		int ans;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i]; 
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				for(int k=1;k<=n;k++){
					jg[i][k]=0;
				}
			}
			dfs(i,0);
			for(int j=i;j<=n;j++){
				for(int k=1;k<=n;k++){
					if(jg[j][k]==2){
						//cout<<i<<" "<<j<<" "<<k<<'\n';
						ans++;
					}
				}
			}
		}
		cout<<ans<<'\n'; 
	}
	
	return 0;
}
