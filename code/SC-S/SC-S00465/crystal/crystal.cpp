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
	fw&operator<<(ll x){wrt(x);return*this;}
	fw&operator<<(int x){wrt(x);return*this;}}out;
ll a[500005],pre[500005];
int fst[500005];
map<ll,int>cnt;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n=read();
	ll m=read();
	for(int i=1;i<=n;++i)a[i]=read();
	sort(a+1,a+1+n);
	pre[1]=a[1],++cnt[a[1]],fst[1]=1;
	for(int i=2;i<=n;++i){
		pre[i]=pre[i-1]+a[i],++cnt[a[i]];
		if(a[i]!=a[i-1])fst[i]=i;
		else fst[i]=fst[i-1];}
	int l=0,ans=0;//l是l-1不是l 
	for(int i=1;i<=n;++i){
		int r=fst[i]-1;
		while(a[i]*(r-l)-(pre[r]-pre[l])>m)++l;
		ans=max(ans,r-l+cnt[a[i]]);}
//	相同能量值必为某一水晶初始能量值,合成的水晶必然连续 
	out<<ans;
	return 0;}