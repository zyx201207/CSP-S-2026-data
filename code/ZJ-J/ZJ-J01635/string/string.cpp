#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn=2e5+5;
int n;
LL ans,len;
struct node{
	LL l,r;
	char ch;
}a[maxn];
LL read(){
	LL ret=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-f;ch=getchar();}
	while('0'<=ch&&ch<='9')ret=(ret<<1)+(ret<<3)+(ch&15),ch=getchar();
	return ret*f;
}
char readc(char l,char r,int lim){
	while(lim--){
		char ch=getchar();
		if(l<=ch&&ch<=r)return ch;
	}
	return 0;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++){
		LL x=read();char ch=readc('a','z',10);
		a[i]={len+1,len+x,ch};len+=x;
	}
	a[0].r=0,a[n+1].l=len+1;
	int id1=0,id2=0;LL l=0,r=0;
	if(len&1)l=r=(len+1)>>1;
	else l=len>>1,r=l+1;
	for(int i=1;i<=n;i++){
		if(a[i].l<=l&&l<=a[i].r)id1=i;
		if(a[i].l<=r&&r<=a[i].r)id2=i;
	}
	while(l){
		LL nxtl=a[id1-1].r,nxtr=a[id2+1].l;
		if(nxtl==len-nxtr+1){
			if(a[id1].ch!=a[id2].ch)ans+=l-nxtl;
			l=nxtl,r=nxtr;id1--,id2++;
		}
		else if(nxtl>len-nxtr+1){
			if(a[id1].ch!=a[id2].ch)ans+=l-nxtl;
			l=nxtl,r=len-nxtl+1;id1--;
		}
		else if(nxtl<len-nxtr+1){
			if(a[id1].ch!=a[id2].ch)ans+=nxtr-r;
			l=len-nxtr+1,r=nxtr;id2++;
		}
	}
	printf("%lld\n",ans);
	return 0;
}