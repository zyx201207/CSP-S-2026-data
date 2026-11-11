#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
long long c,n,m,d,q,a[510005],t,tt=1,f[505][505];
vector<int>v[500005],vv[500005];
long long zhao(long long x,long long y){
	long long ttt=100000000000000;
	for(long long i=0;i<v[x].size();i++){
		for(long long j=0;j<v[y].size();j++){
			
			ttt=min(ttt,f[v[x][i]][v[y][j]]+vv[x][i]+vv[y][j]);
		    //cout<<v[x][i]<<" "<<v[y][j]<<" "<<f[v[x][i]][v[y][j]]+a[x]+a[y]+vv[x][i]+vv[y][j]<<"\n";
		}
	}
	return ttt+a[x]+a[y];
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(long long i=1;i<=m;i++){
		cin>>a[i];
	}
	
	for(long long i=1;i<=n;i++){
		long long k;
		cin>>k;
		for(long long j=1;j<=k;j++){
			long long aa,bb;
			cin>>aa>>bb;
			v[aa].push_back(i);
			vv[aa].push_back(bb);
			}
	}//cout<<"www";
	for(long long i=1;i<=n;i++){
		for(long long j=1;j<=n;j++){
			f[i][j]=100000000000000;
			if(i==j){
				f[i][j]=0;
			}
		}
	}
	for(long long i=1;i<=m;i++){
		for(long long j=0;j<v[i].size();j++){
			for(long long g=0;g<v[i].size();g++){
				if(j==g){
					continue;
				}
				f[v[i][j]][v[i][g]]=min(f[v[i][j]][v[i][g]],1ll*vv[i][j]+1ll*vv[i][g]);
				f[v[i][g]][v[i][j]]=f[v[i][j]][v[i][g]];
			}
		}
	}
	
	for(long long k=1;k<=n;k++){
		for(long long i=1;i<=n;i++){
			for(long long j=1;j<=n;j++){
				if(i==j){
				    continue;
				}
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
				
			}
		}
	}
	
	for(long long i=1;i<=q;i++){
		long long xx,yy;
		cin>>xx>>yy;
		cout<<zhao(xx,yy)<<"\n";
	}
} 
