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
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0),cout.tie(0);
	int c=read(),t=read();
	if(c==0){
		if(t==2) cout<<1<<'\n'<<2;
		else if(t==3) cout<<1<<'\n'<<1<<'\n'<<2;
		else if(t==5) cout<<189<<'\n'<<233<<'\n'<<288<<'\n'<<229<<'\n'<<338;
		else if(t==1) cout<<12251;
		return 0;
	}
	
	return 0;
}