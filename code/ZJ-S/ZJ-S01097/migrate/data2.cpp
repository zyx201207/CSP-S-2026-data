#include<bits/stdc++.h>
#define fst first
#define scd second
#define db double
#define ll long long
#define pb push_back
#define eb emplace_back
#define vi vector<int>
#define sz(x) ((int)x.size())
#define ms(f,x) memset(f,x,sizeof(f))
#define L(i,j,k) for(int i=(j);i<=(k);++i)
#define R(i,j,k) for(int i=(j);i>=(k);--i)
#define ACN(i,H_u) for(int i=H_u;i;i=E[i].nxt)
using namespace std;
//char buf[1<<20],*p1=buf,*p2=buf;
//#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<20,stdin),p1==p2)?EOF:*p1++)
template<typename T>void rd(T&x){
	x=0;bool f=false;char ch=getchar();
	while(ch<48||ch>57)f|=ch==45,ch=getchar();
	while(ch>=48&&ch<=57)x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	x=f?-x:x;
}
template<typename T,typename...Args>
void rd(T&x,Args&...y){rd(x),rd(y...);}
//dfs
mt19937 rnd(time(0));
const int maxn=1000;
const int N=maxn+10;
int a[N];
//wmr
int random(int l,int r){return rnd()%(r-l+1)+l;}
//incra

//lottle
signed main(){
//	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
//	freopen("","r",stdin);
	freopen("migrate.in","w",stdout);
	printf("0 1\n");
	const int n=random(1,1000),m=random(1,n),d=random(1,n);
	printf("%d %d\n",n,m);
	L(i,1,n)printf("%d ",i*d);
	puts("");
	return 0;
}

