#include <bits/stdc++.h>
using namespace std;
#define int long long
int c,n,m,d,p;
int a[500005];
int b[505][505][5];
int vis[505];
int minn=1e9;
int dfs(int st,int en,int cnt,int ls){
	if(st==en){
		return cnt+ls;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==1){
			continue;
		}
		for(int j=1;j<=b[i][0][0];j++){
			if(st==b[i][j][0]){
				for(int l=1;l<=b[i][0][0];l++){
					if(st!=b[i][l][0]){
						vis[i]=1;
						minn=min(minn,dfs(b[i][l][0],en,cnt+b[i][j][1]+ls,b[i][l][1]));
						vis[i]=0;
					}
				}
			}
		}
	}
	return minn;
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>p;
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int p;
		cin>>p;
		b[i][0][0]=p;
		for(int j=1;j<=p;j++){
			cin>>b[i][j][0]>>b[i][j][1];
		}
	}
	while (p--){
		int f,e;
		cin>>f>>e;
		minn=1e9;
		cout<<a[f]+a[e]+dfs(f,e,0,0)<<endl;
	}
		
	fclose(stdin);
	fclose(stdout);
	return 0;
}
