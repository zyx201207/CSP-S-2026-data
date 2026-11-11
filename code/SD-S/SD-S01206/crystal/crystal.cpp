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

inline void Resolution();
int main(){Resolution();return 0;}

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

__int128 a[555555],n,m;

inline uch check(int k){
	__int128 sum=0;
	for(int i=1;i<=k;i++){
		sum+=a[i];
	}__int128 ans=a[k]*k-sum;
	uch f=(ans<=m);
	for(int i=k+1;i<=n;i++){
		(sum-=a[i-k])+=a[i],ans=a[i]*k-sum;
		f|=(ans<=m);
	}return f;
}

inline void Resolution(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	read(n,m);
	for(int i=1;i<=n;read(a[i++]));
	std::sort(a+1,a+n+1);
	int best=-1;
	for(int l=1,r=n,mid;mid=(l+r)>>1,l<=r;){
		if(check(mid)){
			l=(best=mid)+1;
		}else r=mid-1;
	}return writes(best);
}
