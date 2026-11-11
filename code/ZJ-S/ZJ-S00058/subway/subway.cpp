#include<bits/stdc++.h>
using namespace std;
long long q,m,n,d,c,k[555555],a[555][22];
long long stt[555555],t[555][22];
vector<pair<int,long long>> sta[555555],line[555];
long long dd[555][555];
set<pair<long long, int>> p;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++)scanf("%lld",&stt[i]);
	for(int i=1;i<=n;i++){
		scanf("%lld",&k[i]);
		for(int j=1;j<=k[i];j++){
			scanf("%d%lld",&a[i][j],&t[i][j]);
			sta[a[i][j]].push_back({i,t[i][j]});//
//			printf("(sta%d %d %lld)",a[i][j],i,t[i][j]);
			}
	}
	 
	for(int i=1;i<=m;i++){
		for(auto x:sta[i])for(auto y:sta[i]){
			if(x.first==y.first)continue;
			line[x.first].push_back({y.first,x.second+y.second});
		//	printf("(%d %d %lld)\n",x.first,y.first,x.second+y.second);
		}
	}
	memset(dd,127,sizeof(dd));
	for(int i=1;i<=n;i++){
		p.clear();
		dd[i][i]=0;
		for(int j=1;j<=n;j++){
			p.insert({dd[i][j],j});
		}
		for(int j=1;j<=n;j++){
			int x=p.begin()->second;
			p.erase({dd[i][x],x});//printf("(%d->%lld,%d) ",x,dd[i][x],p.begin()->second);
			for(auto y:line[x]){
				if((p.find({dd[i][y.first],y.first}))==p.end())continue;
				p.erase({dd[i][y.first],y.first});
				dd[i][y.first]=min(dd[i][y.first],dd[i][x]+y.second);
				p.insert({dd[i][y.first],y.first});
			}
		}
	//	for(int j=1;j<=n;j++)printf("%lld ",dd[i][j]);
//	puts("");
	}
	for(int i=1;i<=q;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		long long ans=1LL<<60;
		for(auto xx:sta[x]){
			for(auto yy:sta[y]){
				ans=min(ans,dd[xx.first][yy.first]+xx.second+yy.second);
			}
		}
		printf("%lld\n",ans+stt[x]+stt[y]);
	}
}