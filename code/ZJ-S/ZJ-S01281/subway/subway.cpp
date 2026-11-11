#include<bits/stdc++.h>
using namespace std;
vector<int>a[505],t[505];
map<int,map<int,long long>>len[505][505];
long long ans;
int x[500005][25];
int y[500005][25];
int kk[500005];
int w[500005];
int k[505],b,o,p;
int c,n,m,d,q;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++){
		scanf("%d",&w[i]);
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&k[i]);
		for(int j=1;j<=k[i];j++){
			scanf("%d",&b);
			a[i].push_back(b);
			kk[b]++;
			x[b][kk[b]]=i;
			y[b][kk[b]]=j-1;
			scanf("%d",&b);
			t[i].push_back(b);
			for(int l=0;l<j-1;l++){
				len[i][i][l][j-1]=len[i][i][j-1][l]=-1;
			}
		}
	}
	for(int l=1;l<=m;l++){
		for(int i=1;i<=kk[l];i++){
			for(int j=1;j<i;j++){
				len[x[l][i]][x[l][j]][y[l][i]][y[l][j]]=len[x[l][j]][x[l][i]][y[l][j]][y[l][i]]=t[x[l][i]][y[l][i]]+t[x[l][j]][y[l][j]];
			}
		}
	}
	for(int i1=1;i1<=n;i1++){
		for(int i2=0;i2<k[i1];i2++){
			for(int j1=1;j1<=n;j1++){
				for(int j2=0;j2<k[j1];j2++){
					if(len[i1][j1][i2][j2]==0) len[i1][j1][i2][j2]=1e18;
					if(len[i1][j1][i2][j2]==-1) len[i1][j1][i2][j2]=0;
				}
			}
			len[i1][i1][i2][i2]=0;
		}
	}
	for(int l1=1;l1<=n;l1++){
		for(int l2=0;l2<k[l1];l2++){
			for(int i1=1;i1<=n;i1++){
				for(int i2=0;i2<k[i1];i2++){
					for(int j1=1;j1<=n;j1++){
						for(int j2=0;j2<k[j1];j2++){
							len[i1][j1][i2][j2]=min(len[i1][j1][i2][j2],len[i1][l1][i2][l2]+len[l1][j1][l2][j2]);
						}
					}
				}
			}
		}
	}
	while(q--){
		scanf("%d%d",&o,&p);
		ans=1e18;
		for(int i=1;i<=kk[o];i++){
			for(int j=1;j<=kk[p];j++){
				ans=min(ans,len[x[o][i]][x[p][j]][y[o][i]][y[p][j]]+t[x[o][i]][y[o][i]]+t[y[p][j]][t[p][j]]);
			}
		}
		ans+=w[o]+w[p];
		printf("%lld\n",ans);
	}
	return 0;
}