#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,a,b,s,e,x,y,w[500005],l[600],h[500005][25],t[500005][25],f[500][500],dis[500][500];
long long ans;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++){
		scanf("%lld",&w[i]);
	}
	memset(f,0x3f,sizeof(f));
	for(int i=1;i<=n;i++){
		cin>>l[i];
		for(int j=1;j<=l[i];j++){
			scanf("%lld%lld",&a,&b);
			h[a][++h[a][0]]=i;
			t[a][h[a][0]]=b;
			for(int k=1;k<h[a][0];k++){
				f[i][h[a][k]]=f[h[a][k]][i]=t[a][h[a][0]]+t[a][k];
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j) f[i][j]=0;
			dis[i][j]=f[i][j];
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	for(int i=1;i<=q;i++){
		scanf("%lld%lld",&s,&e);
		ans=0x3ffffffffff;
		for(int j=1;j<=h[s][0];j++){
			for(int k=1;k<=h[e][0];k++){
				x=h[s][j];
				y=h[e][k];
				ans=min(ans,dis[x][y]+t[s][j]+t[e][k]+w[s]+w[e]);
			}
		}
		printf("%lld\n",ans);
	}
	return 0; 
}
