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
const int maxn=2e6;
const int N=maxn+10;
int n,f[N],g[N],b[N],c[N];ll a[N],m;
//wmr

//incra

//lottle
signed main(){
//	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate1.out","w",stdout);
	int cid,T;rd(cid,T);
	while(T--){
		rd(n,m);
		L(i,1,n)rd(a[i]);
		L(i,1,n)b[i]=lower_bound(a+1,a+n+1,a[i]-m)-a,c[i]=upper_bound(a+1,a+n+1,a[i]+m)-a-1;
		int ans=0;
		L(i,1,n){
			g[i]=1,f[i]=0;
			L(j,i+1,n){
				int k=max(b[j],i);
				if(k>=j)break;
				f[j]=f[k]+1;
				if(f[k]==f[k+1]&&f[k+1]==f[k+2])g[j]=3;
				else if(f[k]==f[k+1])g[j]=(g[k]==1&&g[k+1]==1?2:3);
				else g[j]=g[k];
				if(g[j]==2)++ans;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
