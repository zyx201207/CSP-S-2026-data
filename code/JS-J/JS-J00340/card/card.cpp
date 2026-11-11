#include <bits/stdc++.h>
using namespace std;
long long n,m,d[500005],d2[500005],c=0;
struct asd{
	int ij;
	bool b1;
}b[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=0;i<n;i++){
		scanf("%lld",&d[i]);
	}
	for(int i=1;i<=n;i++){
		memset(b,0,sizeof(b));
		c=0;
		for(int j=i-1;j<n;j++){
			if(b[d[j]].b1){
				int l=c;
				for(int k=b[d[j]].ij+1;k<l;k++){
						b[d[k]].b1=0;
						b[d[k]].ij=0;
						c--;
						d2[d[k]]--;
				}
			}else{
				d2[d[j]]++;
				b[d[j]].b1=1;
				b[d[j]].ij=j;
				c++;
			}
		}
	}for(int i=1;i<=m;i++){
		printf("%lld ",d2[i]);
	}
	return 0;
}
