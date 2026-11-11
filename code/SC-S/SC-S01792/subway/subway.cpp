#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=507,maxm=5e5+7,inf=(LONG_LONG_MAX>>2);

int c,n,m,d,q;
int w[maxm];
int val[maxm][22];
int num[maxm][22],tl[maxm];
int mp[maxn][maxn],dis[maxn][maxn];

int in(){
	int t=0,k=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') k=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		t=(t<<3)+(t<<1)+(c^48);
		c=getchar();
	}
	return k*t;
}

void out(int x){
	if(x<0) putchar('-'),x=-x;
	if(x<10) putchar(x^48);
	else out(x/10),putchar(x%10^48);
}

signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=in(),n=in(),m=in(),d=in(),q=in();
	memset(mp,0x3f3f3f,sizeof(mp));
	for(int i=1;i<=m;i++) w[i]=in();
	for(int i=1,u=0,v=0,k;i<=n;i++){
		k=in();
		for(int j=1;j<=k;j++){
			u=in(),v=in();
			val[u][++tl[u]]=v;
			num[u][tl[u]]=i;
			for(int tt=1;tt<tl[u];tt++){
				if(mp[i][num[u][tt]]>val[u][tt]+v){
					mp[i][num[u][tt]]=val[u][tt]+v;
					mp[num[u][tt]][i]=mp[i][num[u][tt]];
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			dis[i][j]=mp[i][j];
			if(i==j) dis[i][j]=0;
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	for(int i=1,u,v;i<=q;i++){
		u=in(),v=in();
		int ans=inf;
		for(int fr=1;fr<=tl[u];fr++){
			for(int ed=1;ed<=tl[v];ed++){
				ans=min(ans,dis[num[u][fr]][num[v][ed]]+w[u]+w[v]+val[u][fr]+val[v][ed]);
			}
		}
		out(ans),putchar('\n');
	}
	return 0;
}
//last T2
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/