#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
long long n,m,a[N],pa[N],k,lu[N];
int fa[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	
	long long ju=0;
	while(ju<=n){
		k=0;
		ju++;
		for(int i=1;i<=max(m,n);i++){
			fa[i]=0;
			pa[i]=0;
		}
		
		for(int i=ju;i<=n;i++){
			if(fa[a[i]]==0){
				
				fa[a[i]]=1;
				k++;
				pa[a[i]]=k;
			}else{
				long long cs=0;
				for(int j=pa[a[i]];j<=n;j++){
					fa[a[j]]=0;
					pa[a[i]]=0;
					cs++;
				}
				k-=cs+1;
				pa[a[i]]=k;
				fa[a[i]]=1;
			}
			
		}
		for(int i=1;i<=m;i++){
			if(fa[i]==1){
				lu[i]++;
			}
		}
		
	}
	for(int i=1;i<=m;i++){
		printf("%lld ",lu[i]);
	}
	return 0;
} 
/*
4 3 
1 2 1 3

10 3
3 1 2 1 3 2 3 1 2 1

*/
