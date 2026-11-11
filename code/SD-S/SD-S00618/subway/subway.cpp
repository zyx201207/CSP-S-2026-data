#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
inline int qread(){
	#define qr qread()
	int x=0,c=getchar(),t=1;
	while(c<'0'||c>'9'){
		t^=(c=='-');
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<3)+(x<<1)+c-'0';
		c=getchar();
	}
	return (t?x:-x);
} 
inline void qwrite(int x){
	#define qw(_) qwrite(_)
	#define qws(_) qw(_),putchar(' ')
	#define qwe(_) qw(_),putchar('\n')
	if(x<0) x=-x,putchar('-');
	if(x>9) qw(x/10);
	putchar(x%10+'0');
	return;
}
int w[N],trans[505][505];
struct node{
	int v,t;
};
vector<node>e[N];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c=qr,n=qr,m=qr,d=qr,q=qr;
	for(int i=1;i<=m;i++) w[i]=qr;
	for(int i=1;i<=n;i++){
		int k=qr;
		for(int j=1;j<=k;j++){
			int v=qr,t=qr;
			e[m+i].push_back({v,t});
			e[v].push_back({m+i,t});
		}
	}
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) trans[i][j]=1e18;
	for(int i=1;i<=m;i++){
		for(int j=0;j<e[i].size();j++){
			for(int k=j+1;k<e[i].size();k++){
				int v1=e[i][j].v-m,t1=e[i][j].t,v2=e[i][k].v-m,t2=e[i][k].t;
				trans[v1][v2]=t1+t2;
				trans[v2][v1]=t1+t2;
			}
		}
	}
	for(int i=1;i<=n;i++) trans[i][i]=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			for(int k=1;k<=n;k++)
				trans[i][k]=min(trans[i][k],trans[i][j]+trans[j][k]);
	while(q--){
		int x=qr,y=qr,ans=1e18;
		for(int i=0;i<e[x].size();i++)
			for(int j=0;j<e[y].size();j++)
				ans=min(ans,trans[e[x][i].v-m][e[y][j].v-m]+e[x][i].t+e[y][j].t);
		qwe(ans+w[x]+w[y]);
	}
	return 0;
}
