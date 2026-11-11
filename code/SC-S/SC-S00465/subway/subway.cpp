#include<bits/stdc++.h>
#define ll long long
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
	void wrt(ll x){
		if(x<0)put('-'),x=-x;
		char tmp[20],*t=tmp;
		do *t++=x%10+'0';while(x/=10);
		while(t!=tmp)put(*--t);}
	fw&operator<<(char c){put(c);return*this;}
	fw&operator<<(string&s){wrt(s);return*this;}
	fw&operator<<(int x){wrt(x);return*this;}
	fw&operator<<(ll x){wrt(x);return*this;}}out;
int w[500005];
ll dis[15005][15005];//1~m:地铁站;m+1~m+1+n:地铁线路 
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c=read(),n=read(),m=read(),d=read(),q=read(),sum=n+m,x,y;
	memset(dis,0x3f,sizeof(dis));
	for(int i=1;i<=sum;++i)dis[i][i]=0;
	for(int i=1;i<=m;++i)w[i]=read();
	for(int i=1;i<=n;++i){
		int k=read(),a,t;
		for(int j=1;j<=k;++j)a=read(),t=read(),dis[i+m][a]=dis[a][i+m]=t;}
	for(int k=1;k<=sum;++k)
		for(int i=1;i<=sum;++i)
			for(int j=1;j<=sum;++j)
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	for(int i=1;i<=q;++i)x=read(),y=read(),out<<dis[x][y]+w[x]+w[y]<<'\n';//Floyd 
	return 0;}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/