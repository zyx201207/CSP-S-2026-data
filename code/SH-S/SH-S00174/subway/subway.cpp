#include<iostream>
#include<vector>
#include<cstring> 
#include<limits>
#define ll long long
using namespace std;
const int MAXN=505,MAXM=5e5+5,MAXD=23;
ll dis[MAXN][MAXN];//从线路i换乘到线路j所需最小时间
vector<pair<ll,ll> > D[MAXM];
ll dq[MAXM];
int c,n,m,d,q,k;
ll temp1,temp2;
ll a,b,t;
ll from,to;
ll ans;
int main(){
	memset(dis,0x3f,sizeof(dis));
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)scanf("%lld",dq+i);
	for(int i=1;i<=n;i++){
		scanf("%d",&k);
		for(int j=1;j<=k;j++){
			scanf("%lld %lld",&temp1,&temp2);
			D[temp1].push_back(make_pair(i,temp2));
		}
		//printf("%d\n",i);
	}
	for(int i=1;i<=m;i++){
		int l=D[i].size();
		for(int j=0;j<l;j++){
			for(int s=j+1;s<l;s++){
				a=D[i][j].first;
				b=D[i][s].first;
				t=D[i][j].second+D[i][s].second;
				//printf("%lld %lld %lld\n",a,b,t);
				dis[a][b]=min(dis[a][b],t);
				dis[b][a]=min(dis[b][a],t);
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int s=1;s<=n;s++){
				dis[i][j]=min(dis[i][j],dis[i][s]+dis[s][j]);
			}
		}
	}
	for(int i=1;i<=q;i++){
		ans=LLONG_MAX;
		scanf("%lld %lld",&from,&to);
		for(auto P:D[from]){
			for(auto Q:D[to]){
				a=P.first;
				b=Q.first;
				//printf("%lld %lld %lld %lld\n",a,P.second,b,Q.second);
				if(a==b)ans=min(ans,P.second+Q.second);
				else ans=min(ans,P.second+dis[a][b]+Q.second);
			}
		}
		ans+=dq[from]+dq[to];
		printf("%lld\n",ans);
	}
	return 0;
}
