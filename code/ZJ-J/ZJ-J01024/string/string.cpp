#include<bits/stdc++.h>
using namespace std;
struct duan{
	long long m;
	char x;
}p[200005],c[200005];
int n,o;
long long L,ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);getchar();
	for(int i=1;i<=n;i++){
		long long a;
		char b;
		scanf("%lld",&a);L+=a;getchar();
		b=getchar();
		if(c[o].x==b)c[o].m+=a;
		else c[++o].m=a,c[o].x=b;
	}
	long long k=0;
	if(L%2==0){
		long long sum=0;
		bool f=1;
		for(int i=1;i<=o;i++){
			sum+=c[i].m;
			if(sum==L/2)f=0;
			if(sum>L/2&&f){
				p[++k].m=L/2-(sum-c[i].m),p[k].x=c[i].x;
				p[++k].m=sum-L/2,p[k].x=c[i].x;
				f=0;
			}else p[++k].m=c[i].m,p[k].x=c[i].x;
		}
	}else{
		long long sum=0;
		bool f=1;
		for(int i=1;i<=o;i++){
			sum+=c[i].m;
			if(sum==(L+1)/2)f=0;
			if(sum>(L+1)/2&&f){
				p[++k].m=(L+1)/2-(sum-c[i].m),p[k].x=c[i].x;
				p[++k].m=sum-(L+1)/2,p[k].x=c[i].x;
				f=0;
			}else p[++k].m=c[i].m,p[k].x=c[i].x;
		}
	}
	n=k;
//	for(int i=1;i<=n;i++)printf("%lld %c\n",p[i].m,p[i].x);
	int l=1,r=n;
	while(l<r){
		long long t=min(p[l].m,p[r].m);
		if(p[l].x!=p[r].x)ans+=t;
		p[l].m-=t;p[r].m-=t;
		if(p[l].m==0)l++;
		if(p[r].m==0)r--;
//		printf("%lld ",ans);
	}
	printf("%lld",ans);
	return 0;
}
