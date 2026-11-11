#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,t,n,d,a[305],mp[305][305],cnt[305][305],ans;
void dfs(int nw,int yp,int np){
	if(np<mp[yp][nw])return ;
	if(np==mp[yp][nw]){
		cnt[yp][nw]++;
	}
	for(int i=nw+1;i<=n;i++){
		if(a[i]-a[nw]<=d)dfs(i,yp,np+1);
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		ans=0;
		for(int i=1;i<=n;i++)cin>>a[i];
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j)mp[i][j]=0;
				else if(abs(a[i]-a[j])>d)mp[i][j]=1000000000;
				else mp[i][j]=1;
			}
		} 
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				for(int k=1;k<=n;k++){
					if(mp[i][j]+mp[j][k]<mp[i][k])mp[i][k]=mp[i][j]+mp[j][k];
				}
			}
		}
		for(int i=n;i>=1;i--){
			dfs(i,i,0);
//			cout<<i<<endl;
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(cnt[i][j]==2)ans++;
			}
		}
		cout<<ans<<endl;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++)cnt[i][j]=0;
		}
	}
	return 0;
}
