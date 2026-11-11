#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;
int n,m,a[maxn],ans;
int read_(){
	int ret=0;char ch=getchar();
	while(!isdigit(ch)) ch=getchar();
	while( isdigit(ch))ret=ret*10+ch-'0',ch=getchar();
	return ret;
}
bool cmp(int x,int y){
	return x > y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	n=read_();m=read_();
	for(int i=1;i<=n;i++) a[i]=read_();
	sort(a+1,a+1+n,cmp);
	ans=a[1];
	for(int i=2;i<=m;i++) ans&=a[i];
	cout<<ans;
	return 0;
}
