#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn=2e5+5;
int n,m,cnt[35];
LL ans;
struct node{
	LL x;
	bool b[35];
	bool operator<(const node&B)const{
		for(int i=32;i>=0;i--){
//			printf("%d %d %d %d\n",i,cnt[i],b[i],B.b[i]);
			if(cnt[i]>=m&&b[i]&&!B.b[i])return 1;	
			if(cnt[i]>=m&&!b[i]&&B.b[i])return 0;	
		}
		return 0;
	}
	void calc(){
		int now=x,i=-1;
		while(now)b[++i]=now&1,cnt[i]+=b[i],now>>=1;
	}
//	void print(){
//		printf("%d\n",x);
//		for(int i=32;i>=0;i--)printf("%d",b[i]);
//		putchar('\n');
//	}
}a[maxn];
LL read(){
	LL ret=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-f;ch=getchar();}
	while('0'<=ch&&ch<='9')ret=(ret<<1)+(ret<<3)+(ch&15),ch=getchar();
	return ret*f;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++)a[i].x=read(),a[i].calc();
	sort(1+a,1+a+n);ans=a[1].x;
	for(int i=2;i<=m;i++)ans&=a[i].x;//,a[i].print();
	printf("%lld\n",ans);
//	for(int i=32;i>=0;i--)printf("%d ",cnt[i]);
//	putchar('\n');
//	a[1].x=262143,a[2].x=262142,a[3].x=163381;a[1].calc(),a[2].calc(),a[3].calc();
//	printf("%d %d\n",a[2]<a[3],a[3]<a[2]);
////	sort(1+a,1+a+3);
//	a[1].print();a[2].print();a[3].print();
	return 0;
}