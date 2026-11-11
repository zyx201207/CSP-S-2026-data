#include<bits/stdc++.h>
#define cmin(a,b) a=std::min(a,b)
#define cmax(a,b) a=std::max(a,b)
#define inf ((int)1e18)
#define mod
#define maxn 2000006
#define int long long
#define pb push_back
#define pii std::pair<int,int>
#define arr(x) std::array<int,(x)>
#define fi first
#define se second
bool Mst;
int C,T,n,D,X[maxn];
int L[maxn],R[maxn],fl[maxn],fr[maxn];
int buk[maxn],val[maxn];
void ama10(){
	scanf("%lld%lld",&n,&D);
	for(int i=1;i<=n;i++){
		scanf("%lld",&X[i]);
	}
	for(int i=1,p=1;i<=n;i++){
		while(X[i]-X[p]>D) p++;
		L[i]=p;
	}
	for(int i=n,p=n;i>=1;i--){
		while(X[p]-X[i]>D) p--;
		R[i]=p;
	}
	for(int i=1;i<=n;i++){
		buk[i]=0;
	}
	for(int i=1,p=1;i<=n;i++){
		fl[i]=1+(R[L[i]]==i)*fl[L[i]];
		while(p<=L[i]) buk[R[p]]--,p++;
		fl[i]+=buk[i],buk[R[i]]++;
	}
	for(int i=1;i<=n;i++){
		buk[i]=0;
	}
	for(int i=n,p=n;i>=1;i--){
		fr[i]=1+(L[R[i]]==i)*fr[R[i]];
		while(p>=R[i]) buk[L[p]]--,p--;
		fr[i]+=buk[i],buk[L[i]]++;
	}
	for(int i=1;i<=n;i++){
		if(i!=1&&R[i-1]<R[i]-1) continue;
		fl[i]=1;
	}
	for(int i=1;i<=n;i++){
		if(i!=n&&L[i+1]>L[i]+1) continue;
		fr[i]=1;
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		if(i>=3) val[R[i-2]]+=fl[i-2];
		ans+=val[L[i]+1]*fr[i];
	} 
	printf("%lld\n",ans);
}
void clr(){ // !!!
	for(int i=0;i<=n+1;i++){
		fl[i]=fr[i]=buk[i]=val[i]=0;
	}
}
bool Med;
signed main(){
//	fprintf(stderr,"used: %lld MB\n",(&Med-&Mst)/1024/1024);
	freopen("migrate.in","r",stdin); 
	freopen("migrate.out","w",stdout); 
	scanf("%lld%lld",&C,&T);
	while(T--) ama10(),clr();
	return 0;
}
/*
-std=c++14 -O2 -lm -Wall -Wl,--stack=1234567890
14:54
T 15:14
W 15:20 O(n^2)
D 16:28
W 16:37


0 1
10 5
1 2 5 8 11 13 14 17 18 19

0 1
10 5
2 4 5 7 10 12 14 16 18 20

migrate.exe < migrate1.in > 1.out
migrate.exe < migrate2.in > 2.out
migrate.exe < migrate3.in > 3.out
migrate.exe < migrate4.in > 4.out
migrate.exe < migrate5.in > 5.out
migrate.exe < migrate6.in > 6.out
fc migrate1.ans 1.out
fc migrate2.ans 2.out
fc migrate3.ans 3.out
fc migrate4.ans 4.out
fc migrate5.ans 5.out
fc migrate6.ans 6.out

bool Mst;
int C,T,n,D,X[maxn];
int L[maxn],R[maxn],fl[maxn],fr[maxn];
std::vector<int> pl[maxn],pr[maxn];
std::map<pii,int> mp;
int dis[maxn][maxn],f[maxn][maxn];
int bl(){
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			f[i][j]=0,dis[i][j]=inf;
			if(X[j]-X[i]<=D){
				f[i][j]=1,dis[i][j]=1;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i-1;j>=1;j--){
			for(int k=j+1;k<i;k++){
				if(X[i]-X[k]>D) continue;
				if(dis[j][k]+1<dis[j][i]){
					dis[j][i]=dis[j][k]+1;
					f[j][i]=f[j][k];
				}else if(dis[j][k]+1==dis[j][i]){
					f[j][i]+=f[j][k];
				}
			}
		}
	}
	int res=0;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(f[i][j]==2){
				printf("%lld %lld\n",i,j);
				res++;
			}
		}
	}
	return res;
//	printf("! %lld\n",f[2][7]);
}
void ama10(){
	scanf("%lld%lld",&n,&D);
	for(int i=1;i<=n;i++){
		scanf("%lld",&X[i]);
	}
	for(int i=1,p=1;i<=n;i++){
		while(X[i]-X[p]>D) p++;
		L[i]=p;
	}
	for(int i=n,p=n;i>=1;i--){
		while(X[p]-X[i]>D) p--;
		R[i]=p;
	}
	for(int i=1;i<=n;i++){
		fl[i]=1+(R[L[i]]==i)*fl[L[i]];
		for(int t=L[i]+1;t<i;t++){
			if(R[t]==i) fl[i]++;
		}
	}
	for(int i=n;i>=1;i--){
		fr[i]=1+(L[R[i]]==i)*fr[R[i]];
		for(int t=i+1;t<R[i];t++){
			if(L[t]==i) fr[i]++;
		}
	}
//	for(int i=1;i<=n;i++){
//		printf("%lld -> [%lld,%lld]\n",i,L[i],R[i]);
//	}
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=i+2;j<=n;j++){
			if(R[i]-L[j]==1){
//				ans++; // i->j
				int wl=1,wr=1;
				if(i!=1&&R[i-1]<R[i]-1) wl=fl[i];
				if(j!=n&&L[j+1]>L[j]+1) wr=fr[j];
				ans+=wl*wr;
//				printf("%lld -> %lld %lld %lld\n",i,j,wl,wr);
			}
		}
	} 
	printf("%lld\n",ans);
//	int ret=bl();
//	if(ret!=ans){
//		printf("%lld %lld\n",n,D);
//		for(int i=1;i<=n;i++){
//			printf("%lld ",X[i]); 
//		} 
//		printf("%lld %lld\n",ret,ans);
//		exit(0);
//	}
//	printf("%lld\n",(int)mp.size());
//	for(auto e:mp){
//		printf("%lld %lld %lld\n",e.fi.fi,e.fi.se,e.se);
//	}
	mp.clear();
}
void clr(){ // !!!
	for(int i=0;i<=n+1;i++){
		fl[i]=fr[i]=0;
		pl[i].clear(),pr[i].clear();
	}
}
bool Med;
signed main(){
//	fprintf(stderr,"used: %lld MB\n",(&Med-&Mst)/1024/1024);
	freopen("migrate3.in","r",stdin); 
	scanf("%lld%lld",&C,&T);
//T=100000;
	while(T--){
//		n=10,D=5;
//		std::random_device rd;
//		std::mt19937 mt(time(0));
//		for(int i=1,lst=0;i<=n;i++){
//			lst+=mt()%3+1,X[i]=lst;
//		}
		ama10(),clr();
	}
	return 0;
}
*/


