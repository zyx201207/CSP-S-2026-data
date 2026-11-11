/*
1. 找到直径。
2. 根据直径划分出若干树。
3. 二分答案。 
4. 根据答案求出区间标记。
5. 转对偶，走指针 
*/
#include<cstdio>
#include<vector>
#include<algorithm>
const int N=2e6+5; 
struct {
	int nxt,v;
}s[N];
int p[N],slen;
void push(int u,int v){
	s[++slen]={p[u],v};
	p[u]=slen;
	return ;
}int c,T;
int n,k;
char tg[N];
std::vector<int > hav;
int fa[N],dep[N],dis[N];
int a[N],al;
void dfsd(int x){
	dep[x]=dep[fa[x]]+1,dis[x]=0;
	for(int i=p[x];i;i=s[i].nxt) if(s[i].v!=fa[x]&&!tg[s[i].v]){
		fa[s[i].v]=x;
		dfsd(s[i].v);
		dis[x]=std::max(dis[x],dis[s[i].v]+1);
	}return ;
}void dfsp(int x){
	if(!tg[x]) hav.push_back(dis[x]);
	for(int i=p[x];i;i=s[i].nxt) if(s[i].v!=fa[x]&&!tg[s[i].v]) dfsp(s[i].v);
	return ;
}int cnt[N];
bool check(int x){
	int gl=al+1,gr=0,can=k;
	for(int j:hav) can-=j>=x;
	if(can<0) return false;
	for(int i=1;i<=al;++i){
		cnt[i]=0;
		int b=std::max(0,x-a[i]);
		gl=std::min(gl,i+b);
		gr=std::max(gr,i-b);
	}int gp=gr-gl+1-can;
	if(gp<=0) return true;
	for(int i=1;i<=al;++i){
		int b=std::max(0,x-a[i]);
		if(i-b<=gl||i+b>=gr) continue;
		if(2*b+1>gp) continue;
		++cnt[std::max(1,i+b-gp+1)];
		--cnt[i-b+1];
	}for(int i=1;i<=al;++i){
		cnt[i]+=cnt[i-1];
		if(gl<i&&i+gp-1<gr&&!cnt[i]) return true;
	}return false;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%d%d", &c, &T);
	while(T--){
		scanf("%d%d", &n, &k);
		hav.clear();
		for(int i=1;i<=n;++i){
			p[i]=tg[i]=0;
			fa[i]=dep[i]=dis[i]=0;
		}slen=al=0;
		for(int i=1,u,v;i<n;++i){
			scanf("%d%d", &u, &v);
			push(u,v),push(v,u);
		}int mx=1;
		fa[1]=0;
		dfsd(1);
		for(int i=1;i<=n;++i) if(dep[i]>dep[mx]) mx=i;
		fa[mx]=0;
		dfsd(mx);
		for(int i=1;i<=n;++i) if(dep[i]>dep[mx]) mx=i;
		while(mx){
			tg[mx]=1;
			a[++al]=mx;
			mx=fa[mx];
		}for(int i=1;i<=al;++i){
			fa[a[i]]=0,dfsd(a[i]);
			dfsp(a[i]),a[i]=dis[a[i]];
		}int l=0,r=n;
		while(l<r){
			int mid=(l+r)>>1;
			if(check(mid)) r=mid;
			else l=mid+1;
		}printf("%d\n", l);
	}
	return 0;
}