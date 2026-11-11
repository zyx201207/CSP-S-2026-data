//666t2数组开小导致内存越界我愣是查了快1个多小时导致t3t4都没时间想正解，遗憾止步100+100+24+15=239pts
//拜托不要爆0啊QAQ
//补药让我t1t2爆啊
//图灵在上%%%
//rp+=rp++ + ++rp;
//胡言乱语ing
//正在往代码里添加没用的东西ing.png
//我要进省队我要进省队我要进省队...... 

//啊？我看错时间以为马上交卷了结果还有半个小时QAQ 
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
const int maxm=5e5+10,maxn=505;
int c,n,m,d,q;
int k[maxn];
ll w[maxm];
ll f[maxn][maxn];
std::vector<std::pair<int,ll>> ls[maxm];
int main(){
//	freopen("subway7.in","r",stdin);
//	freopen("subway.out","w",stdout);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	rd(c,n,m,d,q);
	for(int i=1;i<=m;i++){
		rd(w[i]);
	}
	memset(f,0x3f,sizeof(f));
	for(int i=1;i<=n;i++){
		f[i][i]=0;
	}
	for(int i=1;i<=n;i++){
		rd(k[i]);
		for(int j=1;j<=k[i];j++){
			int a;
			ll t;
			rd(a,t);
			for(auto y:ls[a]){
				f[y.first][i]=f[i][y.first]=std::min(f[i][y.first],y.second+t);
			}
			ls[a].push_back({i,t});
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(f[i][k]+f[k][j]<f[i][j]){
					f[i][j]=f[i][k]+f[k][j];
				}
			}
		}
	}
	while(q--){
		int x,y;
		rd(x,y);
		ll ans=0x3f3f3f3f3f3f3f3f;
		for(auto a:ls[x])
		for(auto b:ls[y]){
			ans=std::min(ans,f[a.first][b.first]+a.second+b.second);
		}
		ans+=w[x]+w[y];
		wt(ans,'\n');
	}
	return 0;
}
