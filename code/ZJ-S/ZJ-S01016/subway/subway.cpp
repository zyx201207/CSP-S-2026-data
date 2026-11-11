#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,w[500010],k[500010],now,ti,disst[500010],disli[21],fr,des,ans;
struct d{
	vector<pair<long long,long long> > to;
};
vector<long long> line[21];
map<long long,long long> stat[500010];
bool sd[500010],ld[21];
priority_queue<pair<long long,pair<long long,bool> >,vector<pair<long long,pair<long long,bool> > >,greater<pair<long long,pair<long long,bool> > > > qu;//0--station  1--line
void ch(int x){//line_number
	ld[x]=x&1;
	for(int i=1;i<=n;i++){
		disli[i]=1e18;
	}
	for(int i=1;i<=m;i++){
		disst[i]=1e18;
	}
	for(int i=0;i<line[x].size();i++){
		qu.push({stat[line[x][i]][x],{line[x][i],0}});
		disst[line[x][i]]=stat[line[x][i]][x];
	}
	while(!qu.empty()){
		if((qu.top().second.second==0 && sd[qu.top().second.first]==x&1) || (qu.top().second.second==1 && ld[qu.top().second.first]==x&1)){
			qu.pop();
			continue;
		}
		long long ndis=qu.top().first,nnum=qu.top().second.first;
		bool sty=qu.top().second.second;
		qu.pop();
		if(sty){//now is line
			ld[nnum]=x&1;
			for(int i=0;i<line[nnum].size();i++){
				if(sd[line[nnum][i]]!=x&1 && disst[line[nnum][i]]>ndis+stat[line[nnum][i]][nnum]){
					disst[line[nnum][i]]=disli[nnum]+stat[line[nnum][i]][nnum];
					qu.push({disst[line[nnum][i]],{line[nnum][i],0}});
				}
			}
		}
		else{//now is station
			sd[nnum]=x&1;
			stat[nnum][x]=ndis;
			for(auto i=stat[nnum].begin();i!=stat[nnum].end();i++){
				if(ld[i->first]!=x&1 && disli[i->first]>ndis+i->second){
					disli[i->first]=disst[nnum]+i->second;
					qu.push({disli[i->first],{i->first,1}});
				}
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld %lld %lld %lld %lld",&c,&n,&m,&d,&q);//hao,xianlushu,zhanshu,zuiduojingguoshu,chuxingjihuashu
	for(int i=1;i<=m;i++){
		scanf("%lld",&w[i]);
	}
	for(long long i=1;i<=n;i++){
		scanf("%lld",&k[i]);
		for(long long j=1;j<=k[i];j++){
			scanf("%lld %lld",&now,&ti);
			stat[now][i]=ti;
			line[i].push_back(now);
		}
	}
	for(int i=1;i<=n;i++){
		ch(i);
	}
	while(q--){
		scanf("%lld %lld",&fr,&des);
		ans=stat[fr][1]+stat[des][1];
		for(int i=2;i<=n;i++){
			ans=min(ans,stat[fr][i]+stat[des][i]);
		}
		printf("%lld\n",ans+w[fr]+w[des]);
	}
	return 0;
}
