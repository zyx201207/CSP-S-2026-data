#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N 500010
#define _for(i,u,v) for(int i=(u);i<=(v);i++)
#define for_(i,u,v) for(int i=(u);i>=(v);i--)
int c,n,m,d,q;
int w[N],k[510];
ll fl[510][510];
struct node{
	int i,x;
};
vector<node> a[N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	memset(fl,0x3f,sizeof(fl));
	_for(i,1,m) scanf("%d",&w[i]);
	_for(i,1,n){
		scanf("%d",&k[i]); int b,t;
		fl[i][i]=0;
		_for(j,1,k[i]){
			scanf("%d%d",&b,&t);
			a[b].push_back({i,t});
		}
	} _for(i,1,m){
		int sum=a[i].size();
		_for(j,0,sum-1){
			_for(kk,j+1,sum-1){
				int x=a[i][j].i,y=a[i][kk].i;
				fl[x][y]=fl[y][x]=min(fl[x][y],a[i][j].x*1ll+a[i][kk].x);
			}
		}
	} _for(i,1,n){
		_for(j,1,n){
			_for(kk,1,n){
				fl[i][j]=min(fl[i][j],fl[i][kk]+fl[kk][j]);
			}
		}
	} while(q--){
		int x,y; scanf("%d%d",&x,&y);
		ll ans=1e18;
		for(auto fin:a[x]){
			for(auto res:a[y]){
				ans=min(ans,fl[fin.i][res.i]*1ll+fin.x+res.x);
			}
		} printf("%lld\n",ans+w[x]+w[y]);
	} 
}

