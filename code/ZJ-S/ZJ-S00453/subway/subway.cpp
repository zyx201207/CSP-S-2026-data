#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int head[N],toto[N<<1],nxt[N<<1],val[N<<1];	
int c,n,m,d,Q;
int aa[N];
long long bb[105][2],cc[105][2];
long long a[505][505];
int cnt=0;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&Q);
	for(int i=1;i<=m;++i) scanf("%d",aa+i);
	for(int i=1;i<=n;++i){
		int tt;scanf("%d",&tt);
		for(int j=1;j<=tt;++j){
			int xx,yy;scanf("%d%d",&xx,&yy);
			++cnt;
			toto[cnt]=head[xx];
			val[cnt]=yy;
			nxt[cnt]=i;
			head[xx]=cnt;
		}
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			if(i!=j) a[i][j]=1e18;
		}
	}
	for(int i=1;i<=m;++i){
		int nn=0,j=head[i];
		while(j!=0){
			bb[++nn][0]=nxt[j];
			bb[nn][1]=val[j];
			j=toto[j];
		}
		for(int j1=1;j1<=nn;++j1){
			for(int j2=j1+1;j2<=nn;++j2){
				a[bb[j1][0]][bb[j2][0]]=min(1ll*bb[j1][1]+bb[j2][1],a[bb[j1][0]][bb[j2][0]]);
				a[bb[j2][0]][bb[j1][0]]=min(1ll*bb[j1][1]+bb[j2][1],a[bb[j2][0]][bb[j1][0]]);
			}
		}
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			if(i==j) continue;
			for(int k=1;k<=n;++k){
				if(i==k||j==k) continue;
				if(a[j][i]+a[i][k]<a[j][k]){
					a[j][k]=a[j][i]+a[i][k];
				}
			}
		}
	}
	while(Q--){
		int xx,yy;scanf("%d%d",&xx,&yy);
		int nn=0,j=head[xx];
		while(j!=0){
			bb[++nn][0]=nxt[j];
			bb[nn][1]=val[j];
			j=toto[j];
		}
		int mm=0;j=head[yy];
		while(j!=0){
			cc[++mm][0]=nxt[j];
			cc[mm][1]=val[j];
			j=toto[j];
		}
		long long ans=1e18;
		for(int i=1;i<=nn;++i){
			for(int k1=1;k1<=mm;++k1){
				ans=min(ans,bb[i][1]+cc[k1][1]+a[bb[i][0]][cc[k1][0]]);
			}
		}
		ans+=aa[xx];
		ans+=aa[yy];
		printf("%lld\n",ans);
	}
	return 0;
}
