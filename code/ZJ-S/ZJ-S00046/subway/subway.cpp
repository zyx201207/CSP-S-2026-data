#include<bits/stdc++.h>
using namespace std;
int n,c,m,d,q,w[500005];
vector<int> a[505],v[505],num[500005];
map<int,int> mp[505];
long long f[505][505];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++){
		scanf("%d",&w[i]);
	}
	memset(f,0x3f,sizeof(f));
	for(int i=1;i<=n;i++){
		f[i][i]=0;
		int k;
		scanf("%d",&k);
		for(int j=0;j<k;j++){
			int x,y;
			scanf("%d%d",&x,&y);
			num[x].push_back(i);
			mp[i][x]=j;
			v[i].push_back(y);
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=0;j<num[i].size();j++){
			for(int k=0;k<num[i].size();k++){
				if(j!=k){
					f[num[i][k]][num[i][j]]=f[num[i][j]][num[i][k]]=min(f[num[i][j]][num[i][k]],1ll*v[num[i][j]][mp[num[i][j]][i]]+v[num[i][k]][mp[num[i][k]][i]]);
				}
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
			}
		}
	}
	while(q--){
		int x,y;
		scanf("%d%d",&x,&y);
		long long ans=3e18;
		for(int i=0;i<num[x].size();i++){
			for(int j=0;j<num[y].size();j++){
				ans=min(ans,f[num[x][i]][num[y][j]]+v[num[x][i]][mp[num[x][i]][x]]+v[num[y][j]][mp[num[y][j]][y]]);
			}
		}
		printf("%lld\n",ans+w[x]+w[y]);
	}
	return 0;
}