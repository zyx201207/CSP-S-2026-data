#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;
const int maxm=3e5+5;
int n,m,a[maxn],b[maxm];
int zhan[maxn],ding=0;
int read_(){
	int ret=0;char ch=getchar();
	while(!isdigit(ch)) ch=getchar();
	while( isdigit(ch))ret=ret*10+ch-'0',ch=getchar();
	return ret;
}
void pushin(int x){
	for(int i=ding;i>=1;i--) if(zhan[i]==x){ding=i;return ;}
	zhan[++ding]=x;
}
void check(){
	for(int i=1;i<=ding;i++) b[zhan[i]]++;
	ding=0;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	n=read_();m=read_();
	for(int i=1;i<=n;i++) a[i]=read_();
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++) pushin(a[j]);
		check();
	}
	for(int i=1;i<=m;i++) cout<<b[i]<<' ';
	return 0;
}
