#include<bits/stdc++.h>
using namespace std;
#define N 500000
//         123456
int a[N];
int si[N];
int n,m;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;++i){
		scanf("%d",a+i);
	}
	sort(a,a+n);
	si[0]=0;
	int bm=-1;
	if(m==0)bm=0;
	int lsm=0;
	for(int i=1;i<n;++i){
		si[i]=si[i-1]+i*(a[i]-a[i-1]);
		//printf("%d,",si[i]);
		if(bm==-1&&si[i]>m){
			bm=i;
			lsm=i;
		}
	}
	if(bm==-1){
		printf("%d",n);
		return 0;
	}
	int i=0,j=bm;
	int s=si[bm];
	while(j<n&&i<j){
		int prei=i,prej=j;
		//printf("%d,%d:%d;",i,j,s);
		while(s>m&&i<j){
			s=s-a[j]+a[i];
			i+=1;
		}
		//printf("%d,%d:%d;",i,j,s);
		while(s<=m&&j+1<n){
			j+=1;
			s=s+(j-i)*(a[j]-a[j-1]);
		}
		//printf("%d,%d:%d\n",i,j,s);
		lsm=max(lsm,j-i);
		if(prei==i&&prej==j)break;
	}
	printf("%d",lsm);
}