#include<bits/stdc++.h>
#define ll long long
#define fori(a,b,c) for(ll i=a;i<=b;i+=c)
#define forj(a,b,c) for(ll j=a;j<=b;j+=c)
#define forg(a,b,c) for(ll g=a;g<=b;g+=c)
using namespace std;
const ll N=5e2+5;
const ll M=1e3+5;
ll c,n,m,d,q;
ll v[M],k[N],p[N][N];
struct node{
	ll a,t;
};
vector<node>l[N];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	fori(1,m,1)scanf("%lld",&v[i]);
	fori(1,m,1)forj(1,m,1)p[i][j]=1e9+5;
	fori(1,n,1){
		scanf("%lld",&k[i]);
		forj(1,k[i],1){
			node lll;
			scanf("%lld%lld",&lll.a,&lll.t);
			l[i].push_back(lll);
		}
	}
	forg(1,n,1){
		fori(0,k[g]-1,1){
			forj(i,k[g]-1,1){
				p[l[g][i].a][l[g][j].a]=l[g][i].t+l[g][j].t;
			}
		}
	}
	forg(1,m,1){
		fori(1,m,1){
			if(g==i)continue;
			forj(1,m,1){
				if(g==j||i==j)continue;
				p[i][j]=p[j][i]=min(p[i][j],p[i][g]+p[g][j]);
			}
		}
	}
	while(q--){
		ll x,y;
		scanf("%lld%lld",&x,&y);
		printf("%lld\n",v[x]+v[y]+p[x][y]);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
