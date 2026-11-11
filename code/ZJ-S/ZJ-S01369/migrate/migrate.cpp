#include<bits/stdc++.h>
using namespace std;
int c,t,n,s[5010][5010],vis[5010],f[5010][5010];
long long d,ans,x[5010];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		memset(f,0,sizeof(f));
		cin>>n>>d;
		ans=0;
		int r=1;
		for(int i=1;i<=n;i++){
			cin>>x[i];
			while(r<=i&&x[i]-x[r]>d) r++;
			vis[i]=r;
		}
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				if(vis[j]==j) break;
				if(vis[j]<=i){
					s[i][j]=1;
					f[i][j]=1;
					continue;
				}
				else s[i][j]=1+s[i][vis[j]];
				for(int k=vis[j];k<j;k++) {
					if(s[i][k]==s[i][vis[j]]) f[i][j]+=f[i][k];
					else break;
					if(f[i][j]>2) break;
				}
				if(f[i][j]==2) ans++;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}