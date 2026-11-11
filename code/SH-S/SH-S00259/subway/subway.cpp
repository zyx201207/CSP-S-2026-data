#include<cstdio>
#include<algorithm>
//#define rep(i,a,b) for(int i=a;i<=b;i++)

using namespace std;
int read(){
    int a=0,x=0;
    int ch=getchar();
    for(;ch<'0'||ch>'9';ch=getchar()) x^=ch=='-';
    for(;ch>='0'&&ch<='9';ch=getchar())a=a*10+ch-'0';
    return x?-a:a;
}
int c,m,n,d,q;
long long w[500005];int k[505],a[505][500005],t;
int stline[500005][25],/*stord[500005][25],*/cntline[500005];
int askt[500005][505];long long transfer114[505][505];


inline long long& minn(long long & a,long long b){
	if(a>b) a=b;
	return a;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
//	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	c=read(),n=read(),m=read(),d=read(),q=read();
	for(int i=1;i<=m;i++) w[i]=read();
	for(int i=1;i<=n;i++){
		k[i]=read();
		for(int j=1;j<=k[i];j++)a[i][j]=read(),t=read(),
			stline[a[i][j]][++cntline[a[i][j]]]=i,
//			stord[a[i][j]][cntline[a[i][j]]]=j;
			askt[a[i][j]][i]=t;
	}
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++)transfer114[i][j]=(i==j?0:1ll<<60);
	for(int j=1;j<=m;j++){
		for(int ord1=1;ord1<=cntline[j];ord1++)
			for(int ord2=ord1+1;ord2<=cntline[j];ord2++){
				int line1=stline[j][ord1],line2=stline[j][ord2];
				minn(transfer114[line1][line2],0ll+askt[j][line1]+askt[j][line2]);
				minn(transfer114[line2][line1],transfer114[line1][line2]);
			}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				minn(transfer114[i][j],transfer114[i][k]+transfer114[k][j]);
				minn(transfer114[j][i],transfer114[i][k]+transfer114[k][j]);
			}
		}
	}
	//printf("%d\n",transfer[1][2]);
	int x,y;
	while(q--) {
		scanf("%d%d",&x,&y);
		long long ans0=0ll+w[x]+w[y],ans=1ll<<60;
		for(int ord1=1;ord1<=cntline[x];ord1++)
			for(int ord2=1;ord2<=cntline[y];ord2++){
				int line1=stline[x][ord1],line2=stline[y][ord2];
				minn(ans,0ll+askt[x][line1]+askt[y][line2]+transfer114[line1][line2]);
			}
		printf("%lld\n",ans+ans0);
	}
	return 0;
}
//jia you,  laoyeji! ni neng zuo dao de! 1.224s (-v-) Come on! Come on!
