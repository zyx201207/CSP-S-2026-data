#include<bits/stdc++.h>
#define M 500005
using namespace std;
long long c,n,m,d,q;///c:taskID n:linenum m:stationnum 
///d:maxlineInSingleSt q:tasknum
//long long w[M];
long long ans=LLONG_MAX;
struct STN{
	long long w;///InOutTime
	vector<long long> lne;///lineID
	vector<long long> tme;///WaitLeaveTime
}stn[M];
long long mp[510][510];//LineToLine
long long endln[510];
bool vis[510];
void bfs(long long fst,long long lst){
	queue<pair<long long,long long> > q;//first:id second:waylen
	for(long long i=0;i<stn[fst].lne.size();i++){
		//cout<<fst<<" L"<<stn[fst].lne[i]<<" T="<<stn[fst].tme[i]<<endl;
		q.push({stn[fst].lne[i],stn[fst].tme[i]});
		vis[stn[fst].lne[i]]=1;
	}
	while(!q.empty()){
		pair<long long,long long> nw;
		nw=q.front();
		q.pop();
		//cout<<"now: L"<<nw.first<<" T_All="<<nw.second<<endl;
		if(endln[nw.first]){
			//cout<<"GotEnd T_All="<<nw.second+endln[nw.first]<<endl;
			ans=min(ans,nw.second+endln[nw.first]);
			continue;
		}
		for(long long i=1,nxttme;i<=n;i++){
			if(vis[i]==1 or mp[nw.first][i]==LLONG_MAX){//visited or CannotReach
				continue;
			}
			nxttme=nw.second+mp[nw.first][i];
			//cout<<"Next L"<<i<<" T_All="<<nxttme<<" nowans="<<ans<<endl;
			vis[i]=1;
			if(nxttme>ans) continue;
			q.push({i,nxttme});
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(long long i=0;i<510;i++){///init
		for(long long j=0;j<510;j++){
			mp[i][j]=LLONG_MAX;
		}
	}
	for(long long i=1;i<=m;i++){
		scanf("%lld",&stn[i].w);
	}
	long long aij;long long tij;
	for(long long i=1,x;i<=n;i++){///i:lineID
		scanf("%d",&x);
		for(long long j=1;j<=x;j++){
			scanf("%d%lld",&aij,&tij);
			if(stn[aij].lne.size()!=0){
				for(long long k=0;k<stn[aij].lne.size();k++){//update LineToLineTime
					mp[i][stn[aij].lne[k]]=min(mp[i][stn[aij].lne[k]],stn[aij].tme[k]+tij);
					mp[stn[aij].lne[k]][i]=min(mp[stn[aij].lne[k]][i],stn[aij].tme[k]+tij);
				}
			}
			stn[aij].lne.push_back(i);
			stn[aij].tme.push_back(tij);
		}
	}
	
//	for(long long i=1;i<=m;i++){
//		cout<<"st"<<i<<"\n"<<"w="<<stn[i].w<<"\n";
//		for(long long j=0;j<stn[i].lne.size();j++){
//			cout<<"L"<<stn[i].lne[j]<<" T="<<stn[i].tme[j]<<endl;
//		}
//	}
//	cout<<"======================="<<endl;
//	for(long long i=1;i<=n;i++){
//		for(long long j=1;j<=n;j++){
//			cout<<mp[i][j]<<" ";
//		}
//		cout<<endl;
//	}
//	cout<<"======================="<<endl;
	
	long long st,ed;
	while(q--){
		ans=LLONG_MAX;
		scanf("%d%d",&st,&ed);
		for(long long i=0;i<510;i++){
			endln[i]=0;//clear end lines
			vis[i]=0;//clear visited lines
		}
		for(long long i=0;i<stn[ed].lne.size();i++){
			endln[stn[ed].lne[i]]=stn[ed].tme[i];//mark end lines
		}
		//cout<<st<<" "<<ed<<endl;
		bfs(st,ed);
		printf("%lld\n",ans+stn[st].w+stn[ed].w);
	}
	return 0;
}
