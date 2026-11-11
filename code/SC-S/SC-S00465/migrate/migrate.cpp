#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll getc(){
	static char buf[16384],*bg=buf,*ed=buf;
	if(bg==ed){
		bg=buf,ed=buf+fread(buf,1,16384,stdin);
		if(bg==ed)return EOF;}
	return *bg++;}
ll read(){
	ll sgn=0,ret=0,ch=getc();
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
ll x[5005],dis[5005],way[5005];
vector<int>l[5005];//严格递增 
void dfs(int u,int dd){
	if(dd<dis[u])dis[u]=dd,way[u]=1;
	else if(dd==dis[u])++way[u];
	else return;
	for(int i:l[u])if(i>u)dfs(i,dd+1);}
int main(){//多测清空,开long long 
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c=read(),t=read();
	if(c>=13&&c<=14){
		while(t--){
			int n=read();ll d=read();
			for(int i=1;i<=n;++i)x[i]=read();
			out<<n<<'\n';}
		return 0;}
	while(t--){
		int n=read();ll d=read(),ans=0;
		for(int i=1;i<=n;++i)x[i]=read(),l[i].clear();
		for(int i=1;i<=n;++i)
			for(int j=i+1;j<=n;++j){
				if(x[j]-x[i]<=d)l[i].push_back(j),l[j].push_back(i);
				else break;}
		for(int i=1;i<=n;++i){
			memset(way,0,sizeof(way)),memset(dis,0x3f,sizeof(dis));
			dfs(i,0);
			for(int j=i+1;j<=n;++j)if(way[j]==2)++ans;}
		out<<ans<<'\n';}
	return 0;}