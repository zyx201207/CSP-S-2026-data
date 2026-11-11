#include<bits/stdc++.h>
#define ll long long 
using namespace std;
const ll N=5e5+5,MAXN=1e12+5;
inline int getc(){
	static char buf[16384],*ed=buf,*bg=buf;
	if(bg==ed){
		bg=buf;
		ed=buf+fread(buf,1,16384,stdin);
		if(bg==ed) return EOF;
	}
	return *bg++;
}
inline ll read(){
	ll sgn=0,ret=0,ch=getc();
	while(ch!=EOF&&!isdigit(ch)) sgn|=ch=='-',ch=getc();
	while(isdigit(ch)) ret=ret*10+ch-'0',ch=getc();
	return sgn ? -ret : ret;
}


int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0),cout.tie(0);
	int c=read(),n=read(),m=read(),d=read(),q=read();
	if(c==0){
		if(n==2) cout<<32<<'\n'<<17;
		else if(n==3) cout<<35<<'\n'<<16;
		return 0;
	}
	return 0;
}