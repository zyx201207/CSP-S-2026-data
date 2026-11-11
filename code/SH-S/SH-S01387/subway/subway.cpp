#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,ans,q,f,w[123456],qq[1000][1000],qw[1000][1000],qm[1000000],v,b,vis[123456];
struct QWE{
	int y;
	int z;
};
QWE pq[201][1000000];
long long dfs(long long r,long long ad){
	long long zx=1234567891234567890,er=0,nm=0,sum=0,kl=1234567891234567890;
	if(r==b){
		for(int i=1;i<=qm[r];i++){
			kl=min(kl,qw[pq[r][i].y][r]);
		}
		return kl;
	}
	for(int i=1;i<=qm[r];i++){
		if(vis[qq[pq[r][i].y][pq[r][i].z+1]]==0&&qq[pq[r][i].y][pq[r][i].z+1]!=0){
			cout<<qq[pq[r][i].y][pq[r][i].z+1]<<' ';
			er++;
			vis[qq[pq[r][i].y][pq[r][i].z+1]]=1;
			for(int j=1;j<=qm[qq[pq[r][i].y][pq[r][i].z+1]];j++)
				if(ad=pq[qq[pq[r][i].y][pq[r][i].z+1]][j].y){
					if(dfs(qq[pq[r][i].y][pq[r][i].z+1],pq[qq[pq[r][i].y][pq[r][i].z+1]][j].y)!=-1)
						zx=min(zx,qw[pq[r][i].y][r]+qw[pq[qq[pq[r][i].y][pq[r][i].z+1]][j].y][qq[pq[r][i].y][pq[r][i].z+1]]+dfs(qq[pq[r][i].y][pq[r][i].z+1],pq[qq[pq[r][i].y][pq[r][i].z+1]][j].y));
					else
						sum++;
				}
				else
					if(dfs(qq[pq[r][i].y][pq[r][i].z+1],ad)!=-1)
						zx=min(zx,dfs(qq[pq[r][i].y][pq[r][i].z+1],ad));
					else
						sum++;
			vis[qq[pq[r][i].y][pq[r][i].z+1]]=0;
		}
	}
	if(er==0||sum==qm[r])
		return -1;
	return zx;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>f;
		for(int j=1;j<=f;j++){
			cin>>qq[i][j];
			cin>>qw[i][qq[i][j]];
			qm[qq[i][j]]++;
			pq[qq[i][j]][qm[qq[i][j]]].y=i;
			pq[qq[i][j]][qm[qq[i][j]]].z=j;
		}
	}
	for(int i=1;i<=q;i++){
		ans=0;
		cin>>v>>b;
		if(v==b){
			cout<<0;
		}
		else{
			ans+=w[v];
			ans+=w[b];
			long long asd=1234567891234567890;
			for(int i=1;i<=qm[v];i++)
				asd=min(asd,qw[pq[v][i].y][v]+dfs(v,pq[v][i].y));
			cout<<ans+asd<<endl;
			ans=0;
		}
	}
	return 0;
}


