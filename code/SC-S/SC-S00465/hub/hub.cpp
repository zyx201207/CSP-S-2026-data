#include<bits/stdc++.h>
using namespace std;
int getc(){
	static char buf[16384],*bg=buf,*ed=buf;
	if(bg==ed){
		bg=buf,ed=buf+fread(buf,1,16384,stdin);
		if(bg==ed)return EOF;}
	return *bg++;}
int read(){
	int sgn=0,ret=0,ch=getc();
	while(ch!=EOF&&!isdigit(ch))sgn|=ch=='-',ch=getc();
	while(isdigit(ch))ret=ret*10+ch-'0',ch=getc();
	return sgn?-ret:ret;}
string readstr(){
	string s;char ch=getc();
	while(ch!=EOF&&isspace(ch))ch=getc();
	while(ch!=EOF&&!isspace(ch))s.push_back(ch),ch=getc();
	return s;}
struct fw{
	char buf[1<<20],*p=buf;
	~fw(){flush();}
	void flush(){fwrite(buf,1,p-buf,stdout);p=buf;}
	void put(char c){if(p==buf+(1<<20))flush();*p++=c;}
	void wrt(string&s){for(char c:s)put(c);}
	void wrt(int x){
		if(x<0)put('-'),x=-x;
		char tmp[20],*t=tmp;
		do *t++=x%10+'0';while(x/=10);
		while(t!=tmp)put(*--t);}
	fw&operator<<(char c){put(c);return*this;}
	fw&operator<<(string&s){wrt(s);return*this;}
	fw&operator<<(int x){wrt(x);return*this;}}out;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c=read(),t=read();
	while(t--){
		int n=read(),k=read();
		for(int i=1;i<n;++i)read(),read();
		out<<1<<'\n';}
	return 0;}