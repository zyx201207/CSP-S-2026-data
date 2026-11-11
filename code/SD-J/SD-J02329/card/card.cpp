#include <iostream>
#include <cstdio>
using namespace std;
const int N=5e5+7;
const int M=3e5+7;
int n,m,num[N],ans[M],cn[M],x[N],k;
bool yn[M];
void reset(int yz){
	for(int i=1;i<=m;i++){cn[i]=yn[i]=0;}
	for(int i=1;i<=yz;i++){x[i]=0;}
}
int main(){
	//fin
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	//in
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&num[i]);
	}
	//get
	for(int ii=1;ii<=n;ii++){
		for(int i=ii;i<=n;i++){
			if(yn[num[i]]){
				while(k>cn[num[i]]){
					cn[x[k]]=yn[x[k]]=0,k--;
				}
				k--,cn[num[i]]=0;
			}else yn[num[i]]=1;
			x[++k]=num[i],cn[num[i]]=k;
		}
		for(int i=1;i<=m;i++){
			if(yn[i])ans[i]++;
		}
		reset(ii);
	} 
	//out
	for(int i=1;i<=m;i++){
		printf("%d",ans[i]);
		if(i!=m)printf(" ");
	}
	printf("\n");
	//fout
	fclose(stdin);
	fclose(stdout);
	return 0;
}
 
