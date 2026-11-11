#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+(c-'0');
		c=getchar();
	}
	return x*f;
}
int c,t,n,d,ans,minn;
signed main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=read(),t=read();
	while(t--){
		n=read(),d=read(),ans=0;
		vector<int> a(n+1,0);
		vector<vector<int>> b(n,vector<int>(n+1,0));
		vector<vector<int>> dis(n,vector<int>(n+1));
		for(int i=1;i<=n;i++){
			a[i]=read();
		}
		for(int i=n-1;i>0;i--){
			for(int j=i+1;j<=n;j++){
				if(a[j]-a[i]<=d) b[i][j]=1,dis[i][j]=1;
				else{
					dis[i][j]=n;
					for(int k=i+1;k<=j&&a[k]-a[i]<=d;k++){
						if(dis[k][j]+1<dis[i][j]){
							b[i][j]=b[k][j];
							dis[i][j]=dis[k][j]+1;
						}
						else if(dis[k][j]+1==dis[i][j]){
							b[i][j]+=b[k][j];
						}
					}
				}
				if(b[i][j]==2) ans++;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
