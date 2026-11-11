#include<bits/stdc++.h>
using namespace std;
const int M=5e5+5;
int m,n,c,d,q,w[M],a[M],t[M],x,y,k,f[1005][1005];
struct edge{
	int to,val;
};
vector<edge> e[1005];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
  	cin>>c>>n>>m>>d>>q;
  	for(int i=1;i<=m;i++){
  		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[j]>>t[j];
			for(int p=1;p<j;p++){
				e[a[j]].push_back({a[p],t[j]+t[p]});
				e[a[p]].push_back({a[j],t[j]+t[p]});
				if(c>=0&&c<=8)f[a[p]][a[j]]=f[a[j]][a[p]]=t[j]+t[p];
			}
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			if(!f[i][j])f[i][j]=1e9;
		}
		f[i][i]=0;
	}
	for(int p=1;p<=m;p++){
		for(int i=1;i<=m;i++){
			for(int j=1;j<=m;j++){
				f[i][j]=min(f[i][j],f[i][p]+f[p][j]);
			}
		}
	}
	while(q--){
		scanf("%d %d",&x,&y);
		printf("%d\n",f[x][y]+w[x]+w[y]);
	}
	return 0;
}

