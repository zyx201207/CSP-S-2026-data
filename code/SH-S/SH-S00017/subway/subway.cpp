#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MaxN=500010;
ll C,n,m,nd,nq;
ll a[MaxN];
ll bn[MaxN];
ll bv[30][MaxN];
ll bw[30][MaxN];
ll dis[510][510];
inline ll readi(){
	char rc;ll rx;
	for(rc=getchar();(rc<'0')||('9'<rc);rc=getchar());
	for(rx=0;('0'<=rc)&&(rc<='9');rc=getchar())
		rx=rx*10+(rc^'0');
	return rx;
}
inline void writei(const ll&x){
	if(x>9)
		writei(x/10);
	putchar('0'^(x%10));
}
inline void mmin(ll&x,const ll&y){
	if(x>y)
		x=y;
}
int main(){
	ll rx,ry,rz;
	memset(dis,0x3f,sizeof(dis));
	//*/
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	//*/
	C=readi();n=readi();m=readi();nd=readi();nq=readi();
	for(ll i=1;i<=m;i++)
		a[i]=readi();
	for(ll i=1;i<=n;i++){
		rx=readi();
		while(rx-->0){
			ry=readi();
			bn[ry]++;
			bv[bn[ry]][ry]=i;
			bw[bn[ry]][ry]=readi();
		}
		dis[i][i]=0;
	}
	for(ll i,j,k=1;k<=m;k++){
		for(i=1;i<=bn[k];i++)
			for(j=1;j<=bn[k];j++)
				mmin(dis[bv[i][k]][bv[j][k]],bw[i][k]+bw[j][k]);
	}
	for(ll i,j,k=1;k<=n;k++)
		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++)
				mmin(dis[i][j],dis[i][k]+dis[k][j]);
	for(ll i,j,iq=1;iq<=nq;iq++){
		rz=0x3f3f3f3f3f3f3f3f;
		rx=readi();ry=readi();
		for(i=1;i<=bn[rx];i++)
			for(j=1;j<=bn[ry];j++)
				mmin(rz,dis[bv[i][rx]][bv[j][ry]]+bw[i][rx]+bw[j][ry]);
		writei(a[rx]+a[ry]+rz);
		putchar('\n');
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
