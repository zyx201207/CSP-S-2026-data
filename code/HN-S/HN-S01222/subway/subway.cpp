#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q;
long long w[1000000],k[100];
long long a[200][100],t[200][500010];
long long x,y;
long long s[10000][10000];
//long long ans=2000000000000000000;
//int dfs(int o,int p){
//	p+=w[o];
//	for(int i=1;i<=m;++i){
//		if(s[o][i]){
//			
//		}
//	}
//}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;++i)cin>>w[i];
	for(int i=1;i<=n;++i){
		cin>>k[i];
		for(int j=1;j<=k[i];++j){
			cin>>a[i][j]>>t[i][j];
			s[a[i][j-1]][a[i][j]]=1;
			s[a[i][j]][a[i][j-1]]=1;
		}
	}
//	while(q--){
//		cin>>x>>y;
//		for(int i=1;i<=n;++i)if(t[o][i])ans=min(dfs(o,w[o]),ans);
//		cout<<ans<<"\n";
//		ans=2000000000000000000;
//	}
	cout<<"$&$&*(@#%&%^*&^(&(*&%&#$&$%@!^$%^&$#^%&#%^&^@^%&%^&^#@^%^&^%%*%&*^@^%^$^%&^@&^%#&^%*($#&@%))))"; 
	return 0;
}
