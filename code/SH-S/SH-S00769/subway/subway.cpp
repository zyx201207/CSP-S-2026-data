#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,q;
struct node{
	int pos,dis;
};
vector<node>xian[502];
int w[500002];
vector<pair<int,int> >cnt[500002]; //表示第i个站有哪些线路可以坐
bool visz[500002],visx[502];
int ans;
bool cmp(node aaa,node kkk){
	if(aaa.dis!=kkk.dis) return aaa.dis<kkk.dis;
	return aaa.pos<kkk.pos;
}
int x,y,z;
int s,t;
void bl(int now,int sum){  //目前在站台now，已用sum时间 
//	cout<<now<<" "<<sum<<"\n";
	if(now==t){
		ans=min(ans,sum);
		return;
	}
	for(auto nx:cnt[now]){
		if(visx[nx.first]==true) continue;
		visx[nx.first]=true;
		for(auto nz:xian[nx.first]){
			if(nz.pos==now||visz[nz.pos]==true) continue;
			visz[nz.pos]=true;
			bl(nz.pos,sum+nx.second+nz.dis);
			visz[nz.pos]=false;
		}
		visx[nx.first]=false;
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
//	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
//		int x; cin>>x;
		scanf("%lld",&x);
		while(x--){
//			int y,z; cin>>y>>z;
			scanf("%lld%lld",&y,&z);
			xian[i].push_back({y,z});
			cnt[y].push_back({i,z});
		}
//		sort(xian[i].begin(),xian[i].end(),cmp);
	}
	while(q--){
		cin>>s>>t;
		for(int i=1;i<=m;i++) visz[i]=false;
		for(int i=1;i<=n;i++) visx[i]=false;
		ans=1000000000000000000;
		bl(s,w[s]);
		cout<<ans+w[t]<<"\n";
		printf("%lld\n",ans+w[t]);
	}
	return 0;
}
