#include<bits/stdc++.h>
using namespace std;
#define LL long long 
const int N=5e2+5,M=2e4+5;
int c,n,m,d,q,x,y,l,hd[M];
bool bo[M];
LL an1,an2,w[M];
struct www{
	int to,ne;
	LL tm;
}bi[N*M];
void lj(int a,int b,LL t){
	bi[++l].ne=hd[a];
	bi[l].to=b;
	bi[l].tm=t;
	hd[a]=l;
}void dfs(LL cs,int no){
	if(bo[no])return;
	if(cs>=an2)return;
	if(no==y){
		an2=min(an2,cs);
		return;
	}bo[no]=1;
	for(int i=hd[no];i;i=bi[i].ne)dfs(cs+bi[i].tm,bi[i].to);	
	bo[no]=0;
}void wt(LL o){
	if(o>=10)wt(o/10);
	char c=(o%10)+'0';
	putchar(c);
}int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)scanf("%lld",&w[i]);
	for(int i=1,k;i<=n;i++){
		scanf("%d",&k);
		LL t;
		for(int j=0,a;j<k;j++){
			scanf("%d%lld",&a,&t);
			lj(m+i,a,t),lj(a,m+i,t);
		}
	}while(q--){
		scanf("%d%d",&x,&y);
		an1=w[x]+w[y],an2=LONG_LONG_MAX;
		dfs(0,x);
		wt(an1+an2),putchar('\n');
	}return 0;
	return 0;
}
