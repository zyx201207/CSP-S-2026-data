// 华风夏韵，洛水天依！

/*
走吧 就算我们无法让大雨停下 还有我 陪你在雨里放肆奔跑啊
地球上 天空下 我们做一对傻瓜
你我生来本就注定天真而伟大

你呀 就算下一秒全世界都崩塌 还有我 在你身边说我爱你啊 
做尘埃 做晚霞 我们总会再见的吧
下次见面时我们会手捧鲜花！！！


我要陪你走下去 一直到无边天际
感谢我们无数次交付彼此的勇气

 
我们会穿过流言喧哗 用力开放对吗
天大地大 任我出发 随风去啊 
*/

#include<bits/stdc++.h>

#define int long long
//#define double long double
#define il inline
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define rpe(i,a,b) for(int i=(a);i>=(b);--i)
#define pii pair<int,int>
#define st first
#define nd second
#define mp make_pair
#define pb push_back

#define multitest 0

using namespace std;
bool mem_beg;

const int N=500+5,M=5e5+5,V=6e5+5,mod=998244353;
const int dx[10]={0,1,-1,0,0,1,1,-1,-1},dy[10]={0,0,0,1,-1,1,-1,1,-1};
const double eps=1e-9;

il void read(int &x){char c;while((c=getchar())<'0'||c>'9');x=c^48;while((c=getchar())>='0'&&c<='9')x=(x<<1)+(x<<3)+(c^48);}
il void chmin(int &a,const int b){b<a&&(a=b);}

int __T=1,test_id;

int n,m,d,q,dis[N][N],w[M],len[N];
//vector <signed> a[N];
vector <pair<signed,signed>> b[M];
//vector <int> t[N];

il void floyd()
{
	rep(k,1,n) rep(i,1,n) rep(j,1,n) chmin(dis[i][j],dis[i][k]+dis[k][j]);
}

il void Solve()
{
	{
		read(n),read(m),read(d),read(q); rep(i,1,m) read(w[i]);
		int _a,_t;
		rep(i,1,n)
		{
			read(len[i]);//,a[i].resize(len[i]+5),t[i].resize(len[i]+5);
			rep(j,1,len[i]) read(_a),read(_t),b[_a].pb(mp(i,_t));
		}
	}
	
	{
		rep(i,1,n) rep(j,1,n) dis[i][j]=1e18;
		
		int tmp;//,ax,ay,tx,ty;
		rep(j,1,m)
		{
			tmp=b[j].size();
			rep(x,0,tmp-1) rep(y,x+1,tmp-1) chmin(dis[b[j][x].st][b[j][y].st],b[j][x].nd+b[j][y].nd);
//			rep(x,0,tmp-1)
//			{
//				ax=b[j][x].st,tx=b[j][x].nd;
//				rep(y,x+1,tmp-1)
//				{
//					ay=b[j][y].st,ty=b[j][y].nd;
//					chmin(dis[ax][ay],tx+ty);
//				}
//			}
		}
		
		rep(i,1,n)
		{
			dis[i][i]=0;
			rep(j,1,n) dis[i][j]=dis[j][i]=min(dis[i][j],dis[j][i]);
		}
	}
	
	floyd();
	
	{
		int x,y,tm1,tm2,ans;
		while(q--)
		{
			read(x),read(y);
			tm1=b[x].size(),tm2=b[y].size(),ans=1e18;
			rep(i,0,tm1-1) rep(j,0,tm2-1)
			{
				chmin(ans,b[x][i].nd+dis[b[x][i].st][b[y][j].st]+b[y][j].nd);
//				b[x][i].st==b[y][j].st&&(chmin(ans,b[x][i].nd+b[y][j].nd),1);
			}
			
			ans+=w[x]+w[y];
			printf("%lld\n",ans);
		}
	}
}

il void Init()
{
	read(test_id);
}

il void Clear()
{

}

bool mem_end;
signed main()
{
	freopen("subway.in","r",stdin),freopen("subway.out","w",stdout);
//	ios::sync_with_stdio(0);
//	fprintf(stderr,"Memory = %.3lf MB\n\n",abs(&mem_beg-&mem_end)/1024./1024.);
	multitest&&(read(__T),1),Init();
	rep(__Ti,1,__T) Solve(),__Ti!=__T&&(Clear(),1);
//	fprintf(stderr,"\nTime = %.3lf ms\n",clock()*1e3/CLOCKS_PER_SEC);
	return 0;
}

/*
不是这个 B 题面怎么这么绕，，花费 20min 去理解题意说是（） 

1~11 44pts | O(m^3) m<=500 | Floyd
15:45 把线路作为点跑floyd就可以了。。。 O(md^2+n^3) - O(qd^2)，大概 3e8 

fc subway.out subway.ans
16:13 样例都一遍过了？啊？我一年没学是怎么在csp上过两个题的。。。 
图论不好拍不拍了。 
*/
