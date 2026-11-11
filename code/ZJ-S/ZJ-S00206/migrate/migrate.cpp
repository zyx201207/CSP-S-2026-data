#include<bits/stdc++.h>
#define int long long
#define N 2000050
#define rep(i,x,y) for(int i=x;i<=y;++i)
#define dep(i,x,y) for(int i=x;i>=y;--i)
using namespace std;
inline int read(){
	int seg=0,sgn=0;char ch;
	while(!isdigit(ch))sgn|=ch=='-',ch=getchar();
	while(isdigit(ch))seg=seg*10+ch-'0',ch=getchar();
	return sgn?-seg:seg;
}
int c,T,n,d,x[N];
struct node{
	int id,len;
};
inline void Main(){
	n=read();d=read();
	rep(i,1,n)x[i]=read();
	
	if(c==1||c==2){
		int ans=0;
		rep(i,1,n)
			rep(j,i+1,n){ 
				int mi=LONG_LONG_MAX,sum=0;
				queue<node>Q;
				Q.push((node){i,0});
				while(!Q.empty()){
					node tmp=Q.front();
					Q.pop();
					
					if(tmp.id==j){
						if(tmp.len<mi){mi=tmp.len;sum=1;}
						else if(tmp.len==mi)++sum;
					}
					
					int k=tmp.id+1;
					while(k<=n&&x[k]-x[tmp.id]<=d){
						Q.push((node){k,tmp.len+1});
						++k;
					}
				}
				if(sum==2)++ans;
			}
		cout<<ans<<'\n';
	}
	
	else if(c==11||c==12){
		int gong=x[2]-x[1],tot=d/gong;
		if(tot<=1||n<=tot*2-1)cout<<0<<'\n';
		else cout<<n-(tot*2-1)<<'\n';
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	//mt19937 Rand(time(0));
	c=read();T=read();
	while(T--)Main();
	return 0;
}

