#include<bits/stdc++.h>
using namespace std;
long long sum=0;
long long mid1,mid2,cnt=0,ma,mi;
const int N=2e5+5;
const int M=1e9+5;
long long h[N]={0}; 


int neew[N];
struct sss{
	long long a;
	char m;
};
struct sff{
	int neew;
	int sf;
};
sff f[N];
sss ss[N];
bool check(long long ans,long long css){
	if(ans>css){
		return 0; 
	}
	if(ans<=css){
		return 1;
	}
}

int main(){
//	freopen("string.in","r",stdin);
//	freopen("string.out","w",stdout);
	int n;
	scanf("%d",&n);
	ss[0].a=1;
	char sfc[n];
	for(int i=1;i<=n;i++){
		scanf("  ");
		scanf("%d",&ss[i].a);
		sum+=ss[i].a;
		h[i]=ss[i].a+h[i-1];
		scanf("  ");
		scanf("%c",&ss[i].m);
	}
	if(n==1){
		printf("0");
		return 0;
	}
	if(sum%2==0){
		mid1=sum/2;
		mid2=mid1+1;
	}else mid1=mid2=sum/2+1;
	int j,xx,yy;
	for(int i=1;i<=n;i++){
		if(check(ss[i].a,mid1)){
			mi=ss[i].a;
			ma=ss[i+1].a;
			xx=yy=j=i;
		}
	}
	
	for(int i=1;i<=n/2+1;i++){
		int t=min(mid1-mi,ma-mid2); 
		f[xx].neew=t;
		f[yy].neew=t;
		xx-=t;
		yy+=t;
		ma=mid2+1;
		mid2=ss[j+i].a;
		mi=mid1-1;
		mid1=ss[j-i].a;
	}
	int lin;
	for(int asd=1;asd<=xx+yy;asd++) {
		for(int i=1;i<=xx+yy;i++){
			if(check(ss[asd].a,f[i].neew)){
				lin=ss[asd].a;
			}
		}
		f[asd].sf=ss[asd].m;
	}
	for(int i=1;i<=xx+yy+1;i++){
		if(f[xx+i].sf==f[yy-i].sf ){
			cnt+=0;
		}else{
			cnt+=neew[i];
		}
	}
	printf("%lld",cnt);
	return 0;
}
