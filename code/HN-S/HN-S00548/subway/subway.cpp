#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll inf=1e16,M=5e5+5,N=505,D=22,Q=1e5+5;
struct node{
	ll nd,t;
}l[M][D];
ll _i,i,j,c,n,m,d,q,w[M],k,x,y,z,cnt[M],fg[N][N],ng,ans,sum,g;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			if(i==j){
				fg[i][j]=0;
			}
			else{
				fg[i][j]=inf;	
			}
		}
	}
	for(i=1;i<=m;i++){
		cin>>w[i];
	}
	for(i=1;i<=n;i++){
		cin>>k;
		for(j=1;j<=k;j++){
			cin>>z;
			cnt[z]++;
			l[z][cnt[z]].nd=i;
			cin>>l[z][cnt[z]].t;
			for(_i=1;_i<cnt[z];_i++){
				g=l[z][_i].nd;
				ng=l[z][_i].t+l[z][cnt[z]].t;
				fg[i][g]=min(fg[i][g],ng);
				fg[g][i]=fg[i][g];
			}
		}
	}
	for(_i=1;_i<=n;_i++){
		for(i=1;i<=n;i++){
			for(j=1;j<=n;j++){
				fg[i][j]=min(fg[i][j],fg[i][_i]+fg[_i][j]);
			}
		}
	}
	while(q--){
		ans=inf;
		cin>>x>>y;
		for(i=1;i<=cnt[x];i++){
			for(j=1;j<=cnt[y];j++){
				sum=w[x]+l[x][i].t+fg[l[x][i].nd][l[y][j].nd]+l[y][j].t+w[y];
				ans=min(ans,sum);
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
