#include<bits/stdc++.h>
namespace chuazen{
	#define ufor(i,x,y) for(int i=x;i<=y;i++)
	#define dfor(i,x,y) for(int i=x;i>=y;i--)
	#define N 500005
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

int c,n,m,d,q;
int gi[N], t[501][501];
pair<int,int> gc[N][21];
int cnt,tmpx,tmpy,ans;

inline void input(){
	c=read(), n=read(), m=read(), d=read(), q=read();
	ufor(i,1,m)gi[i]=read();
	ufor(i,1,n){
		cnt=read();
		ufor(j,1,cnt){
			tmpx=read(), tmpy=read();
			gc[tmpx][++gc[tmpx][0].first]=make_pair(i,tmpy);
		}
	}
}
inline void solve(){
	memset(t,0x3f,sizeof(t)); ufor(i,1,n)t[i][i]=0;
	ufor(i,1,m){
		if(gc[i][0].first<2)continue;
		ufor(j1,1,gc[i][0].first)ufor(j2,1,gc[i][0].first){
			if(j1==j2)continue;
			t[gc[i][j1].first][gc[i][j2].first]=min(t[gc[i][j1].first][gc[i][j2].first], gc[i][j1].second+gc[i][j2].second);
		}
	}
	ufor(k,1,n)ufor(i,1,n)ufor(j,1,n)t[i][j]=min(t[i][j], t[i][k]+t[k][j]);
}
inline void query(){
	tmpx=read(), tmpy=read(), ans=0x3f3f3f3f3f3f3f3f;
	ufor(i,1,gc[tmpx][0].first)ufor(j,1,gc[tmpy][0].first)
		ans=min(ans, t[gc[tmpx][i].first][gc[tmpy][j].first] + gc[tmpx][i].second + gc[tmpy][j].second);
	write(ans+gi[tmpx]+gi[tmpy]), putchar('\n');
}

signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	input();
	solve();
	while(q--)query();

	fclose(stdin);
	fclose(stdout);
	return 0;
}
