#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=5e5+5,M=505;
ll c,n,m,d,q,k[N],w[N],tot;
ll vis[N]; //有没有记录过这个地铁站 ,标记时间 
struct node{
	ll a,t;
};
struct chan{
	ll a,b,t;
}a[N];//表示a线和b线换乘所用的最短时间 
vector<node> e[M],arr[N],st[N];
//e中a指线路，t指进出站时间 
//arr中a指能到的地铁站，t指能到此地铁站的线路 
//st指经过第i个站点的线路,a指线路，t指出入站台时间 
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld %lld %lld %lld %lld",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++){
		scanf("%lld",&w[i]);
	}
	for(int i=1;i<=n;i++){
		scanf("%lld",&k[i]);
		for(int j=1;j<=k[i];j++){
			ll A,TT;//A是站点，TT是出入站台时间 
			scanf("%lld%lld",&A,&TT);
			e[i].push_back({A,TT});
			st[A].push_back({i,TT});
		}
	}
	//if(n<=3){
		for(int S=1;S<=m;S++){
			int len=st[S].size();
			if(len>=2)
				for(int ii=0;ii<len;ii++)
					for(int jj=ii+1;jj<len;jj++){
						ll T=st[S][ii].t+st[S][jj].t;
						bool ok=0,kk=0;
						if(st[S][ii].a>st[S][jj].a){
							swap(st[S][ii].a,st[S][jj].a);
							kk=1;
						}
						
						for(int i=1;i<=tot;i++)
							if(a[i].a==st[S][ii].a&&a[i].b==st[S][jj].a){
								ok=1;
								if(a[i].t>T) a[i].t=T;
							}
						if(!ok) a[++tot]={st[S][ii].a,st[S][jj].a,T};
						if(kk) swap(st[S][ii].a,st[S][jj].a);
						//cout<<a[tot].t<<'\n';
					}
			
		}
		for(int i=1;i<=tot;i++)
			for(int j=1;j<=tot;j++)
				for(int K=1;K<=tot;K++){
					if(i!=j&&j!=K&&i!=K){
						int a1=a[i].a,b1=a[i].b;
						int a2=a[j].a,b2=a[j].b;//1,2换乘 得3 
						int a3=a[K].a,b3=a[K].b;
						if(a1==a3&&b2==b3&&b1==a2&&a[i].t+a[j].t<a[K].t) a[K].t=a[i].t+a[j].t;
					}
				}
		while(q--){
			ll x,y;
			scanf("%lld%lld",&x,&y);
			ll sum=1e9;
			//cout<<st[x].size()<<' '<<st[y].size()<<'\n';
			for(int i=0;i<st[x].size();i++)
				for(int j=0;j<st[y].size();j++){
					if(st[x][i].a==st[y][j].a) sum=min(sum,st[x][i].t+st[y][j].t);
					else for(int K=1;K<=tot;K++){
							if(a[K].a==st[x][i].a&&a[K].b==st[y][j].a||
							a[K].b==st[x][i].a&&a[K].a==st[y][j].a){
								sum=min(sum,st[x][i].t+st[y][j].t+a[K].t);
								//cout<<sum<<'\n';
								break;
							}
						}
				}
			sum+=w[x]+w[y];
			printf("%lld\n",sum);
		}
	//}
	return 0;
} 
