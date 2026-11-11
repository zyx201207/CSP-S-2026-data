//CSP-S 2026 RP++
#include<bits/stdc++.h>
#define gc getchar()
#define ll unsigned long long
#define pc(_) putchar(_)

using namespace std;

const int N=600;
const int M=5e5+100;

int n,m,q,c,d;
ll w[M];
ll dis[N][N];//两个地铁站之间的最短距离
ll e,Head[M],Next[M],To[M],W[M];

inline ll rd(){
	ll x=0;char ch=gc;
	while(!isdigit(ch)) ch=gc;
	while(isdigit(ch)) {x=(x<<3)+(x<<1)+(ch^48);ch=gc;}
	return x;
}

inline void add(int u,int v,ll t){
	To[++e]=v;
	Next[e]=Head[u];
	Head[u]=e;
	W[e]=t;
	return;
}

void init(){
	c=rd();n=rd();m=rd();d=rd();q=rd();	
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
		dis[i][j]=LLONG_MAX;
	for(int i=1;i<=n;i++) dis[i][i]=0;
	for(int i=1;i<=m;i++) w[i]=rd();
	//for(int i=1;i<=m;i++) cout<<w[i]<<" ";cout<<endl;
	for(int i=1;i<=n;i++){
		int k=rd();
		for(int j=1;j<=k;j++){
			int a=rd();ll t=rd();
		//	cout<<a<<" "<<i<<" "<<t<<endl;
			add(a,i,t);
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=Head[i];j;j=Next[j]){
			for(int k=Head[i];k;k=Next[k]){
				if(j!=k){
					if(dis[To[j]][To[k]]>W[j]+W[k]){
						dis[To[j]][To[k]]=W[j]+W[k];
					}
				}
			}	
		}
	}
	//floyd
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(k!=i&&j!=i){
					dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
				}
			}
		}
	}
	return;
}

inline ll work(int s,int t){
	ll res=w[s]+w[t];
	ll ans=LLONG_MAX;
	for(int i=Head[s];i;i=Next[i]){
		for(int j=Head[t];j;j=Next[j]){
			if(ans>dis[To[i]][To[j]]+W[i]+W[j]){
				ans=dis[To[i]][To[j]]+W[i]+W[j];
		//		cout<<To[i]<<" "<<To[j]<<endl;
			}
		}
	}
	return ans+res;
}

inline void wt(ll x){
	if(x<0) x=-x,pc('-');
	if(x>9) wt(x/10);
	pc(x%10+48);
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	init();
	while(q--){
		int x=rd(),y=rd();
		wt(work(x,y));
		pc('\n');
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}