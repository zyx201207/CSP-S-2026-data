#include<bits/stdc++.h>

using ll=long long;
char *p1,*p2,buf[100000];
#define gc() (p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++)
template<typename t>
t rd(t&x){
    x=0;
    int c=gc(),f=1;
    while(!isdigit(c)) f=(c=='-'?-1:1),c=gc();
    while(isdigit(c)) x=x*10-'0'+c,c=gc();
    x*=f;
    return x;
}
template<typename t,typename...ts>
void rd(t&x,ts&...y){
    rd(x);rd(y...);
}
template<typename t>
void wt(t x){
    static int st[64],tp;
    tp=0;
    if(!x) return putchar('0'),void();
    if(x<0){
        putchar('-');
        x=-x;
    }
    while(x) st[++tp]=x%10,x/=10;
    while(tp) putchar(st[tp--]+'0');
}
template<>
void wt(char x){putchar(x);}
template<typename t,typename...ts>
void wt(t x,ts...y){
    wt(x);wt(y...);
}

const int maxn=1e6+10;
int c,t;
int n,k;
std::vector<int> to[maxn];
bool flag[maxn];
bool chk(int c){
	for(int i=1;i<=n;i++){
		flag[i]=0;
	}
	for(int i=0;i<n;i++){
		if((c>>i)&1){
			flag[i+1]=1;
		}
	}
	int cnt=k*2;
	for(int i=1;i<=n;i++){
		if(flag[i])for(int y:to[i]){
			if(flag[y]) cnt--;
		}
	}
	if(cnt<=4) return true;
	else return false;
}
int dis[maxn];
void dfs(int x,int fa,int di){
	for(int y:to[x]){
		if(dis[y]>di+1){
			dis[y]=di+1;
			dfs(y,x,di+1);
		}
	}
}
int val(){
	int res=0;
	for(int i=1;i<=n;i++){
		dis[i]=0x3f3f3f3f;
		if(flag[i]) dis[i]=0;
	}
	for(int i=1;i<=n;i++){
		if(flag[i]){
			dfs(i,0,0);
		}
	}
	for(int i=1;i<=n;i++){
		res=std::max(res,dis[i]);
	}
	return res;
}
int main(){
//	freopen("hub.in","r",stdin);
//	freopen("hub.out","w",stdout);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	rd(c,t);
	while(t--){
		rd(n,k);
		for(int i=1;i<=n;i++) to[i].clear(); 
		for(int i=1;i<n;i++){
			int u,v;
			rd(u,v);
			to[u].push_back(v);
			to[v].push_back(u);
		}
		int ans=0x3f3f3f3f;
		for(int c=0;c<(1<<n);c++){
			if(__builtin_popcount(c)==k){
				if(chk(c)){
					ans=std::min(ans,val());
				}
			}
		}
		wt(ans,'\n');
	}
	return 0;
}
