//刘启安 SN-S00332 西北大学附属中学 
#include <bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,w[5000001],i0[501][500001],i1[501][500001],k[500001],r1[500001],r2[500001],mi; 
long long zo(int x,int y){
	int li=-1;
	for(int i=0;i<n;i++){
		for(int j=0;j<k[i];j++){
			if(r1[x]==i0[i][j]){
				for(int l=0;l<k[i];l++){
					if(r2[x]==i0[i][l]){
						return 0; 
					}
				}
			}
			li=min(li,i1[i][j]);
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<k[i];j++){
			if(r1[i][j]==li){
				return zo(x,r0[i][j]);
			}
		}
	}	
}
int main(){
	//freopen("subway.in","r",stdin);
	scanf("%ld%ld%ld%ld%ld",&c,&n,&m,&d,&q);
	for(int i=0;i<m;i++){
		scanf("%ld",&w[i]);
	}
	for(int i=0;i<n;i++){
		scanf("%ld",&k[i]);
		for(int j=0;j<n;j++){
			scanf("%ld%ld",&i0[i][j],&i1[i][j]);
		}
	}
	for(int i=0;i<q;i++){
		scanf("%ld%ld",&r1[i],&r2[i]);
	} 
	for(long long p=0;p<q;p++){
		mi=w[r1[p]]+zo(p,r1[o])+w[r2[p]];
		printf("%ld",mi);
	}
	return 0;
	//freopen("subway.out","w",stdout);
}
