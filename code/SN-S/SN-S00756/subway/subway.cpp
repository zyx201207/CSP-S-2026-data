#include<bits/stdc++.h>
using namespace std;
long long minn=9999999999,ans;
long long c,n,m,d,q,v[500005],w[500005],a[505][500005],t[505][500005],x,y,k[500005];
void dfs(int zx){//zx是第几个地铁站 
	v[zx]=1; 
	for(int i=1;i<=n;i++){
		for(int j=1;j<=k[i];j++){
			if(a[i][j]==zx){
				for(int z=1;z<=k[i];z++){
					if(v[z]==0){
						ans=ans+t[i][z]+t[i][zx];
						minn=min(minn,ans);
						dfs(zx);
						ans=ans-t[i][z]-t[i][zx];
					}
				}
				break;
			}
		}
	}
	v[zx]=0;
	if(zx==y)return;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;//线路数,站数,最多被几线路过，出行计划数
	for(int i=1;i<=m;i++)cin>>w[i];//地铁口-站时间 
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];//a[i][j]第i条第j个站t[i][j]站厅-站台时间
		}
	}
	while(q--){
		minn=9999999999;
		cin>>x>>y;
		cout<<0<<"\n";
		ans=ans+w[y]+w[x];
		dfs(x);
		cout<<minn<<"\n";
	} 
	return 0;
}
//空悲切！！！！为什么编译不了不显示！！！！！！！！！！！！！ 
