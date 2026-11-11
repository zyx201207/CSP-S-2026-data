#include<bits/stdc++.h>
using namespace std;
long long read(){
	long long ret=0,ty=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')
			ty=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
		ret=ret*10+c-'0',c=getchar();
	return ret*ty;
}
long long c,t,n,k,u,v;
vector<long long> e[1000009];
vector<vector<long long> > rec;
long long fa[1000009][25],dep[1000009];
bool in[1000009],vst[1000009];
void dfs(long long u,long long f){
	fa[u][0]=f,dep[u]=dep[f]+1;
	for(long long i=1;i<=log2(n);i++)
		fa[u][i]=fa[fa[u][i-1]][i-1];
	for(long long v:e[u])
		if(v!=f)
			dfs(v,u);
}
void dfs2(long long u){
	if(!in[u]||vst[u])
		return;
	vst[u]=1;
	for(long long v:e[u])
		dfs2(v);
}
void dfs3(long long i,long long siz,vector<long long> now){
	if(siz>k)
		return;
	if(siz==k){
		rec.push_back(now);
		return;
	}
	if(i==n+1){
		return;
	}
	dfs3(i+1,siz,now);
	now.push_back(i);
	dfs3(i+1,siz+1,now);
}
long long lca(long long x,long long y){
	if(dep[x]<dep[y])
		swap(x,y);
	for(long long i=log2(n);i>=0;i--)
		if(dep[fa[x][i]]>=dep[y])
			x=fa[x][i];
	if(x==y)
		return x;
	for(long long i=log2(n);i>=0;i--)
		if(fa[x][i]!=fa[y][i])
			x=fa[x][i],y=fa[y][i];
	return fa[x][0];
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	c=read(),t=read();
	while(t--){
		long long ans=1e16;
		n=read(),k=read();
		rec.clear();
		for(long long i=1;i<=n;i++)
			e[i].clear();
		for(long long i=1;i<n;i++)
			u=read(),v=read(),e[u].push_back(v),e[v].push_back(u);
		dfs(1,0);
		vector<long long> tmp;
		tmp.push_back(0);
		dfs3(1,0,tmp);
		for(vector<long long> recc:rec){
			fill(vst+1,vst+n+1,0);
			fill(in+1,in+n+1,0);
			long long cnt=0;
			for(long long i=1;i<=k;i++){
				in[recc[i]]=1;
			}
			for(long long i=1;i<=n;i++)
				if(!vst[i]&&in[i])
					dfs2(i),cnt++;
			if(cnt>2)
				continue;
			long long mx=-1;
			for(long long i=1;i<=n;i++){
				long long mn=1e16;
				for(long long j=1;j<=k;j++){
					long long x=i,y=recc[j],f=lca(x,y);
					mn=min(mn,dep[x]+dep[y]-2*dep[f]);
				}
				mx=max(mx,mn);
			}
			ans=min(ans,mx);
		}
		cout<<ans<<"\n";
	}
	return 0;
} 
/*
qianyan:
xiangshang chouxiangdashang
luogu uid:951011
huanyin huguan
----------------------------------------------
14:41 bushi zenme du jia ti le wo hai yiwei keyi +1-1 ne
na bushi erfen + qianzhuihe miao le
14:52 erfen xiegua le yici danshi guole
#define int long long ->ctrl+f int -> long long    : )
bushi zenme xiecheng signed int le
shoupi zheyikuai
----------------------------------------------
14:56 zheti haoxiang bunan
ba zhantai he zhanting chaikai lianbian ranhou pao zuiduanlu
danshi zheyang hui tle
jiang yitiao xianlu shangde suoyou zhanting shiwei tongyige
!@#$%^&* zenme you ba n&m dufanle
zai yuanxian silu de jichushang women xuanze buqu kaolv zhandian zhijiande zuiduanlu
ershi kaolv xianlu zhijiande zuiduanlu
zheyang sihu yao O((m+q+d)(d^2)) de fuzadu 
zhongsuozhouzhi ccf ganghuan le shaoyeji
suoyi yinggai neng guo
15:42 chabuduo lishunle
kaishixie
16:02 wocao zhege shuchu he daan daxiao zenme chale 100k
wocao zenme fc zhaobudao chayi
wocao xiasi shushu wo le hai yiwei floyd jicuo le
16:09 paole yibian lemonlime queding 200 pts le
zhexia suibian da le
----------------------------------------------
16:30 huile O(n^3) de zuofa he A xingzhi
17:37 wo zenme zhidao weishenme guole zhemejiu
zongzhi hui de fen xiechulai le
----------------------------------------------
17:50 haoxiang zhihui O(2^k*n^2) de zuofa
eee buguan le xian xie ba
18:17 jieshu 15pts
----------------------------------------------
houji:
zongfen: 100+100+32+15=247pts?
xue oi 4th nian
zhe ge chengqi hai suan neng jieshou
gg
*/ 
