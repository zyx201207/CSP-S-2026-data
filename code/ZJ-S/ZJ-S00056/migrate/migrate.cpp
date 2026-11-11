#include<bits/stdc++.h>
#define int long long

const int N=2e6+10;

using namespace std;

int cid,T;

int n,d,ans;

int a[N];

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')ret=ret*10+(ch&15),ch=getchar();
	return ret*f;
}

int f[310][310];

int t[310][310];

inline int _mul(int x,int y){
	int B=1e9,tmp=x*y;
	return tmp<B?tmp:B;
}

void _solve(){
	n=read(),d=read();
	ans=0;
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)f[i][j]=1e18,t[i][j]=0;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(a[j]-a[i]<=d){
				f[i][j]=1;
				t[i][j]=1;
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(f[i][k]+f[k][j]==f[i][j]){
					t[i][j]+=_mul(t[i][k],t[k][j]);
				}
				if(f[i][k]+f[k][j]<f[i][j]){
					f[i][j]=f[i][k]+f[k][j];
					t[i][j]=_mul(t[i][k],t[k][j]);
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(t[i][j]==2){
				ans++;
			}
		}
	}
	printf("%lld\n",ans);
}

signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cid=read(),T=read();
	while(T--)_solve();
	return 0;
}

/*

0 1
10 272727272727272724

-999999999999999976 
-727272727272727252 
-454545454545454528 
-181818181818181804 
-90909090909090896 
12 
181818181818181828 
454545454545454552 
727272727272727276 
1000000000000000000

*/