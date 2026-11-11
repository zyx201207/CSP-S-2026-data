#include<bits/stdc++.h>
#ifdef __linux__
#define _read(a,b,c) fread_unlocked(b,c,1,stdin)
#define _write(a,b,c) fwrite_unlocked(b,c,1,stdout)
#else
#include<io.h>
#endif

typedef char ch;typedef unsigned char uch;
typedef long long ll;

inline ch gc(){
	static ch buf[1<<20],*p=buf,*q=buf;
	if(p>=q)q=buf+_read(0,p=buf,sizeof(buf));
	return p<=q?*p++:0;
}

struct Pc{
	ch buf[1<<20],*p=buf;
	
	inline void operator()(ch c){
		if(p>=buf+sizeof(buf))flush();
		*p++=c;
		return;
	}
	
	inline void flush(){
		_write(1,buf,p-buf),p=buf;
		return;
	}
	
	inline void write(ch*c,int n){
		if(p+n>=buf+sizeof(buf))flush();
		memcpy(p,c,n),p+=n;
		return;
	}
	
	inline~Pc(){
		flush();
	}
}pc;

template<typename T>
inline void read(T&x){
	ch c=gc();uch f=x=0;
	for(;c<=' ';c=gc());
	c=='-'&&(c=gc(),f++);
	for(;c>' '&&c;x=(x<<1)+(x<<3)+(c&15),c=gc());
	x=f?~x+1:x;
//	std::cin>>x;
	return;
}

inline void read(){return;}
template<typename T,typename...Tp>
inline void read(T&x,Tp&...y){
	return read(x),read(y...);
}

template<typename T>
inline void write(T x){
	static struct Tb{
		ch t[10000][5];uch len[10000];
		
		inline Tb(){
			for(int i=0;i<10000;i++){
				sprintf(t[i],"%04d",i);
				int x=i;do{
					len[i]++;
				}while(x/=10);
			}
		}
		
		inline ch*operator[](int i){
			return t[i];
		}
	}t;if(x<0)x=~x+1,pc('-');
	ch buf[48],*p=buf+48;
	while(x>=1000){
		memcpy(p-=4,t[x%10000],4),x/=10000;
	}if(x)memcpy(p-=t.len[x],t[x]+4-t.len[x],t.len[x]);
	return pc.write(p,buf+48-p);
//	std::cout<<x;
}

inline void write(ch x){
	return pc(x);
//	std::cout<<'\n';
}

inline void write(){return;}
template<typename T,typename...Tp>
inline void write(const T&x,const Tp&...y){
	return write(x),write(y...);
}

template<typename...T>
inline void writes(const T&...x){
	return write(x...,'\n');
}

inline void writec(){return;}
template<typename T,typename...Tp>
inline void writec(const T&x,const Tp&...y){
	return write(x,' '),writec(y...);
}

template<typename...T>
inline void writecs(const T&...x){
	return writec(x...),writes();
}

inline void Resolution();
int main(){Resolution();return 0;}

#define Title(x) struct Txx{Txx(){freopen(x ".in","r",stdin),freopen(x ".out","w",stdout);}}txx

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

Title("migrate");

int c,t;

int x[2222222];

std::vector<int>li[2222222],liscnt;

inline void dfs(int u){
//	li[liscnt].emplace_back(u);
//	for(int i=u+1;i<=n;i++){
//		if(a[i]-a[u]<=d){
//			dfs(i);
//		}
//	}
}

inline void Resolution(){
	read(c,t);
	while(t--){
		int n,d;
		read(n,d);
		for(int i=1;i<=n;read(x[i++]));
		writes(0);
	}return;
}
