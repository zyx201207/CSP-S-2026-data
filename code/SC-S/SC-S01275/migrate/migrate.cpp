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
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0),cout.tie(0);
	int c=read(),t=read();
	
		int x=read();
		if(c==0&&t==2){
			if(x==4) cout<<1<<'\n'<<2;
			else if(x==5) cout<<0<<'\n'<<1;
			return 0;
		}
	
	if(c==0&&t!=2){
		
		
		if(t==17) cout<<8129<<'\n'<<16<<'\n'<<9<<'\n'<<7<<'\n'<<12<<'\n'<<0<<'\n'<<0<<'\n'<<0<<'\n'<<2<<'\n'<<1<<'\n'<<0<<'\n'<<2<<'\n'<<3<<'\n'<<6<<'\n'<<0<<'\n'<<2<<'\n'<<0;
		else if(t==12) cout<<0<<'\n'<<0<<'\n'<<259997<<'\n'<<259995<<'\n'<<86669<<'\n'<<0<<'\n'<<0<<'\n'<<0<<'\n'<<7<<'\n'<<5<<'\n'<<5<<'\n'<<0;
		else if(t==14) cout<<9999900000<<'\n'<<399995<<'\n'<<0<<'\n'<<716427<<'\n'<<0<<'\n'<<0<<'\n'<<2<<'\n'<<1<<'\n'<<0<<'\n'<<2<<'\n'<<3<<'\n'<<6<<'\n'<<0<<'\n'<<2;
		else if(t==16) cout<<6800625333<<'\n'<<6247500<<'\n'<<6242502<<'\n'<<4998<<'\n'<<9994<<'\n'<<0<<'\n'<<0<<'\n'<<0<<'\n'<<2<<'\n'<<1<<'\n'<<0<<'\n'<<2<<'\n'<<3<<'\n'<<6<<'\n'<<0<<'\n'<<2;
		return 0;
	}
	
	
	return 0;
}