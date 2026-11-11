#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn=200005;
LL n,a[maxn],s[maxn],l,lj,r,rj,ans;
char b[maxn];
int read(){
	int num=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-f;ch=getchar();}
	while(isdigit(ch))num=num*10+ch-'0',ch=getchar();
	return num*f;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
		s[i]=s[i-1]+a[i];
		char ch=getchar();
		while(!(ch>='a' && ch<='z'))ch=getchar();
		b[i]=ch;
	}
	LL j=1;
	while(s[j]<(s[n]+1)/2 && j<=n)j++;
	if(s[n]&(LL)1){
		l=(s[n]+1)/2-1;
		if((s[n]+1)/2-s[j-1]==1)lj=j-1;
		else lj=j;
		r=(s[n]+1)/2+1;
		if(s[j]-(s[n]+1)/2==0)rj=j+1;
		else rj=j;
	}
	else{
		l=(s[n]+1)/2;
		lj=j;
		r=(s[n]+1)/2+1;
		if(s[j]-(s[n]+1)/2==0)rj=j+1;
		else rj=j;
	}
	while(l>=1 && r<=s[n] && lj>=1 && rj<=n){
		LL x=l-s[lj-1],y=s[rj]-r+1,z;
		if(x<y)z=x;
		if(y<x)z=y;
		if(x==y)z=x;
		if(b[lj]!=b[rj])ans+=z;
		l-=z,r+=z;
		if(x<y)lj--;
		if(y<x)rj++;
		if(x==y)lj--,rj++;
	}
	cout<<ans;
	return 0;
}