#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n,m;const int N=1e5+100;
LL w[N],d,q,r[N],k,c;
LL a[510][500100];
map<LL,LL>mp;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++)scanf("%lld",&w[i]);
   for(int i=1;i<=n;i++){
	   scanf("%lld",&k);
	   for(int j=1;j<=k;j++){
		   LL num,x;
		   scanf("%lld%lld",&num,&x);
		   a[i][num]=x;
	   }
   }
	for(int i=1;i<=q;i++){
		LL s1,t1,ans=0;
		scanf("%lld%lld",&s1,&t1);
		
			for(int j=1;j<=m;j++){
				if(a[1][t1]!=0){
					ans+=a[1][t1];
					ans+=w[t1];
				}else{
					for(int i=2;i<=n;i++){
						if(a[i][t1]!=0){
					
						}
					}
				}
			}
	
	}
}