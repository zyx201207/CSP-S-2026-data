#include<bits/stdc++.h>
using namespace std;
long long c,d,m,n,q,w[501100],dist[1111][1111];
struct way{
	long long pr,to;
};
vector<way> edge[501100];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1; i<=m; i++) scanf("%lld",&w[i]);
	
	memset(dist,0x3f,sizeof(dist));
	for(int i=1; i<=n; i++){
		long long k,uo,up;
		cin>>k;
		for(int j=1; j<=k; j++){
			scanf("%lld%lld",&uo,&up);
			dist[uo][m+i]=up;
			dist[m+i][uo]=up;
		}
	}
	
	for(int k=1; k<=m+n; k++){
		for(int i=1; i<=m+n; i++){
			for(int j=1; j<=m+n; j++){
				if(dist[i][k]+dist[j][k]<dist[i][j]){
					dist[i][j]=dist[i][k]+dist[j][k];
				}
			}
		}
		
	}
	for(int i=1; i<=q; i++){
		long long st,en;
		long long an=0;
		scanf("%lld%lld",&st,&en);
		an+=w[st];an+=w[en];
		an+=dist[st][en];
		cout<<an<<endl;
	}
	return 0;
} 
