#include<bits/stdc++.h>
using namespace std;
#define maxn 200005
#define int long long
int n,a[maxn],L,ans;
char c[maxn];
int read(){
	int f=1,ret=0;
	char ch=getchar();
	while(!isdigit(ch)){if(ch=='-'){f=-1;}ch=getchar();}
	while(isdigit(ch)){ret=ret*10+ch-'0';ch=getchar();}
	return ret*f;
}
int lst,lstp;
//lstp:上一次找到的下标 
//lst:上一次找到a[lstp]时还剩下几个元素 
//往前找dis个元素,与x不同元素的个数 
int how_many(int dis,char x){
	if(lst>=dis){
//		printf("$\n");
		lst-=dis;
		if(x==c[lstp]) return 0;
		else return dis;
	}
//	printf("@\n");
	int sum=0;
	if(x!=c[lstp]) sum+=lst;
//	printf("%lld ",sum);
	dis-=lst;
	lstp--;
	while(a[lstp]<dis){
		dis-=a[lstp];
		if(x!=c[lstp]) sum+=a[lstp];
//		printf("%lld ",sum);
		lstp--;
	}
	lst=a[lstp]-dis;
	if(x!=c[lstp]) sum+=dis;
//	printf("%lld ",sum);
	return sum;
}
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++){
		a[i]=read(),c[i]=getchar();
		L+=a[i];
	}
	lst=a[n];
	lstp=n;
	int p=1,sum=0;
	while(sum+a[p]<=L/2) sum+=a[p],p++;
	for(int i=1;i<p;i++){
		int x=how_many(a[i],c[i]);
		ans+=x;
//		printf("%lld %lld %lld\n",a[i],c[i],x);
	}
	int x=how_many(L/2-sum,c[p]);
	ans+=x;
//	printf("%lld %lld %lld\n",sum,L/2,x);
	printf("%lld",ans);
	return 0;
}
