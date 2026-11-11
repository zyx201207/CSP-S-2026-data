#include <bits/stdc++.h>
using namespace std;
long long c,n,m,d,r,k,ans;
int x,y;
long long w[130010];
long long t[500][130010],a[500][130010];
int dfs(int x){
	if(x==y)return ans;
	for(int i=1;i<=n;i++){
		if(a[i][1]==x){
			 ans+=t[i][1]+t[i][2];
			 x=a[i][2];
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>r;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(int i=1;i<=r;i++){
		cin>>x>>y;
		ans=0;
		ans=w[x]+w[y];
		dfs(x);
		cout<<ans<<endl;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}

