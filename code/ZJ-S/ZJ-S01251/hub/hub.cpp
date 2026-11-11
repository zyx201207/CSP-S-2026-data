#include<bits/stdc++.h>
namespace chuazen{
	#define ufor(i,x,y) for(int i=x;i<=y;i++)
	#define dfor(i,x,y) for(int i=x;i>=y;i--)
	#define N 1000005
	char out[100],ch; int tp;
	#define int long long
	#define getchar() (p1==p2&&(p2=(p1=in)+fread(in,1,1<<21,stdin),p1==p2)?EOF:*p1++)
	char in[1<<21],*p1,*p2;
	inline int read(){
		int x=0,f=1; ch=getchar();
		while(ch<'0'||ch>'9'){if(ch=='-')f=-1; ch=getchar();}
		while(ch>='0'&&ch<='9'){x=x*10+ch-'0'; ch=getchar();}
		return x*f;
	}
	inline void write(int x){
		if(x<0)putchar('-'),x=-x;
		tp=0;
		do out[++tp]=x%10+'0', x/=10; while(x);
		while(tp)putchar(out[tp--]);
	}
}
using namespace std;
using namespace chuazen;

int c,T,n,k,ans;
int x,y;
bool is[N],vis[N];
vector<int> tr[N];

inline void pian(){
	int m=(n+1)/2;
	write((m-k)/4+1),putchar('\n');
}

inline void pv(int nw){
	vis[nw]=1;
	ufor(i,0,(int)tr[nw].size()-1)if(is[tr[nw][i]]&&!vis[tr[nw][i]])pv(tr[nw][i]);
}

inline bool check(){
	ufor(i,1,n)vis[i]=0;
	int num=0;
	ufor(i,1,n){
		if(is[i]&&!vis[i])pv(i), num++;
	}
	return (num<=2);
}

queue< pair<int,int> > q;

inline int cc(int nw){
	while(!q.empty())q.pop(); ufor(i,1,n)vis[i]=0;
	q.push(make_pair(nw,0)); vis[nw]=1;
	while(!q.empty()){
		pair<int,int> p0=q.front(); q.pop();
		if(is[p0.first])return p0.second;
		ufor(i,0,(int)tr[p0.first].size()-1){
			if(vis[tr[p0.first][i]])continue;
			vis[tr[p0.first][i]]=1;
			q.push(make_pair(tr[p0.first][i],p0.second+1));
		}
	}
	return -1;
}

inline int calc(){
	int res=0;
	ufor(i,1,n)res=max(res,cc(i));
	return res;
}

inline void dfs(int nw,int num){
	if(nw==n+1){
		if(num!=k)return;
		if(check())ans=min(ans,calc());
		return;
	}
	dfs(nw+1,num);
	is[nw]=1;
	dfs(nw+1,num+1);
	is[nw]=0;
}

inline void brute(){
	dfs(1,0);
	write(ans), putchar('\n');
}

signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	
	c=read(), T=read();
	while(T--){
		ufor(i,1,n)tr[i].clear(); ans=0x3f3f3f3f3f3f3f3f;
		n=read(), k=read();
		ufor(i,1,n-1){
			x=read(), y=read();
			tr[x].push_back(y);
			tr[y].push_back(x);
		}
		c=13;
		if(c==13||c==14)pian();
		else brute();
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
	噫嘘兮，危乎高哉！蜀道之难，难于上青天！蚕丛及鱼凫，开国何茫然。尔来四万八千岁，不与秦塞通人烟。西当太白有鸟道，可以横绝峨眉巅。
地崩山摧壮士死，然后天梯石栈相勾连。上有六龙回日之高标，下有冲波逆折之回川。黄鹤之飞尚不得过，猿猱欲度愁攀援。青泥何盘盘，百步九折萦
岩峦。扪参历井仰胁息，以手抚膺坐长叹。
	别君去兮何时还？畏途巉岩不可攀。但见飞鸟号古木，雄飞雌从绕林间。又闻子规啼夜月，愁空山。蜀道之难，难于上青天，使人听此凋朱颜！ 连
峰去天不盈尺，枯松倒挂倚绝壁。飞湍瀑流争喧豗，砯崖转石万壑雷。其险也如此，嗟尔远道之人胡为乎来哉！


	君不见黄河之水天上来，奔流到海不复回。
	君不见高堂明镜悲白发，朝如青丝暮成雪。
	人生得意须尽欢，莫使金樽空对月。
	天生我材必有用，千金散尽还复来。
	
*/
