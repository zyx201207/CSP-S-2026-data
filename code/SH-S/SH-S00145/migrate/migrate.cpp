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
const int maxn=2e6+10;
int c,t,n;
ll d,ans;
ll x[maxn];
std::vector<int> to[maxn];
std::queue<int> q;
int dis[maxn],cnt[maxn];
bool chk(int s){
	q.push(s);
	for(int i=s;i<=n;i++){
		dis[i]=0x3f3f3f3f;
		cnt[i]=0;
	}
	dis[s]=0;
	cnt[s]=1;
	while(!q.empty()){
		int x=q.front();
		q.pop();
		for(int y:to[x]){
			if(dis[y]<dis[x]+1) continue;
			else if(dis[y]==dis[x]+1){
				if(cnt[y]==2) ans--;
				cnt[y]+=cnt[x];
			}
			else{
				dis[y]=dis[x]+1;
				q.push(y);
				if(cnt[y]==2) ans--;
				cnt[y]+=cnt[x];
			}
			if(cnt[y]==2) ans++;
		}
	}
}
int main(){
//	freopen("migrate.in","r",stdin);
//	freopen("migrate3.out","w",stdout);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	rd(c,t);
	while(t--){
		rd(n,d);
		for(int i=1;i<=n;i++){
			rd(x[i]);
			to[i].clear();
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(x[j]-x[i]>d) break;
				to[i].push_back(j);
			}
		}
		ans=0;
		for(int i=1;i<=n;i++){
			chk(i);
		}
		wt(ans,'\n');
	}
	return 0;
}
