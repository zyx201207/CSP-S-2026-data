#include<bits/stdc++.h>
using namespace std;
struct N{
	long long a,t;
}l[505][50005];
vector<long long> zl[50005];
long long c,n,m,d,q,k[100005],w[100005],bj[100005],zt[50005][505],zzj[50005][505],sum,p,b;
long long dfs(long long x,long long st){
//	cout<<x<<'\n';
	if(x==b){
		return zt[x][st];
	}
	long long lsum=2e18;
	for(long long i=0;i<zl[x].size();i++){
//		cout<<"***";
		if(bj[l[zl[x][i]][zzj[x][zl[x][i]]+1].a]==0){
//			cout<<"###";
			if(st!=zl[x][i]){
				long long ddd=dfs(l[zl[x][i]][zzj[x][zl[x][i]]+1].a,zl[x][i])+zt[x][zl[x][i]]+zt[x][st];
				if(lsum>ddd){
//					cout<<"&&&";
				   lsum=ddd;
				}
			}
		}
		else {
			if(lsum>dfs(l[st][x+1].a,st)){
//				cout<<"$$$";
				lsum=dfs(l[st][x+1].a,st);
			}
		}
	}
//	cout<<"lsum"<<lsum<<'\n';
	return lsum;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio();
	cin.tie(),cout.tie();
	cin>>c>>n>>m>>d>>q;
	for(long long i=1;i<=m;i++){
		cin>>w[i];
	}
	for(long long i=1;i<=n;i++){
		cin>>k[i];
		for(long long j=1;j<=k[i];j++){
			cin>>l[i][j].a>>l[i][j].t;
			zl[l[i][j].a].push_back(i);
			zt[l[i][j].a][i]=l[i][j].t;
			zzj[l[i][j].a][i]=j;
		}
	}
	while(q--){
		memset(bj,0,sizeof(bj)); 
		cin>>p>>b;
		long long minn=2e18,bjtt=0;
		for(long long i=0;i<zl[p].size();i++){
//			cout<<zl[p][i]<<' '<<zl[p].size()<<' '<<l[zl[p][i]][zzj[p][zl[p][i]+1]].a<<' '<<zzj[p][zl[p][i]]+1<<'\n';
			long long dd=dfs(l[zl[p][i]][zzj[p][zl[p][i]]+1].a,zl[p][i]);
			if(minn>dd){
				minn=dd;
				bjtt=zl[p][i];
			}
		}
		sum=w[p]+w[b]+minn+zt[p][bjtt];
		cout<<sum<<'\n';
	}
	return 0;
}