#include<bits/stdc++.h>
using namespace std;
const int N=5e2+5,M=5e5+5;
int c,n,m,d,q,w[N],k,a,t,sip[M],jl[N][N],dp[N][N];
struct node{
	int time,xian;
}p[M][20];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a>>t;
			p[a][++sip[a]]={t,i};
		}
	}for(int i=1;i<=m;i++){
		for(int j=1;j<=sip[i];j++){
			for(int o=1;o<j;o++){
				if(jl[p[i][j].xian][p[i][o].xian]==0){
					jl[p[i][j].xian][p[i][o].xian]=p[i][j].time+p[i][o].time;
					jl[p[i][o].xian][p[i][j].xian]=p[i][j].time+p[i][o].time;
				}else{
					jl[p[i][j].xian][p[i][o].xian]=max(p[i][j].time+p[i][o].time,jl[p[i][j].xian][p[i][o].xian]);
					jl[p[i][o].xian][p[i][j].xian]=max(p[i][j].time+p[i][o].time,jl[p[i][o].xian][p[i][j].xian]);
				}
			}
		}
	}for(int i=1;i<=n;i++){
		jl[i][i]=0;
		for(int j=1;j<=n;j++){
			if(i==j)continue;
			for(int o=1;o<=n;o++){
				if(i==o||o==j)continue;
				if(jl[i][o]==0||jl[o][j]==0)continue;
				jl[i][j]=min(jl[i][o]+jl[o][j],jl[i][j]);
				jl[j][i]=jl[i][j];
			}
		}
	}
	for(int i=1;i<=q;i++){
		int l,r,ans=1000000000;
		cin>>l>>r;
		for(int i=1;i<=sip[l];i++){
			for(int j=1;j<=sip[r];j++){
				ans=min(ans,p[l][i].time+p[r][j].time+jl[p[l][i].xian][p[r][j].xian]);
//				cout<<p[l][i].time+p[r][j].time+jl[p[l][i].xian][p[r][j].xian]<<' ';
			}
		}cout<<ans+w[l]+w[r]<<'\n';
	}
	return 0;
}
