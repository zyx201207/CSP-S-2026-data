#include<bits/stdc++.h>
#define int long long
using namespace std;
//mt19937_64 rnd(chrono::steady_clock::now().time_since_epoch().count()^((uint64_t)random_device{}()<<32)^(uint64_t)random_device{}());
vector<pair<int,int> >lane[555];//lane[?]=sites that lane_? can reach and the time
vector<pair<int,int> >site[500555];//site[?]=lanes that site_? can reach and the time
int dsite[500555];//dsite[?]=the time that site_? to exit_?
int dlane[555][555];//dlane[a][b]=the least time from lane_a to lane_b
//WARNING: dlane DONT include beginning site to a lane
int lane_site[500555];//lane_site[?] in the case[dij(x)]=the least time from lane_x to site_?
int c,n,m,d,Q;
struct state{
	bool f;//this state is lane(0) or site(1)
	int dis,id;
	friend bool operator <(state a,state b){
		return a.dis>b.dis;
	}
};
priority_queue<state>pq;
inline void dij(int st){
	fill(&lane_site[0],&lane_site[m+11],LONG_LONG_MAX/4);
	dlane[st][st]=0;
	while(!pq.empty()){
		pq.pop();
	}
	state t,tmp;
	t.f=1;//to sites
	for(auto&&to:lane[st]){//sites that lane_st can reach
		t.id=to.first;
		t.dis=to.second;
		lane_site[t.id]=t.dis;
		pq.push(t);
	}
	while(!pq.empty()){
		t=pq.top();pq.pop();
		if(t.f){//now in site
			if(t.dis>lane_site[t.id]){//the time is worse
				continue;
			}
			tmp.f=0;//next state is in lane
			for(auto&&to:site[t.id]){//lanes that now site can reach
				tmp.id=to.first;
				tmp.dis=t.dis+to.second;
				if(tmp.dis<dlane[st][tmp.id]){//a lower time:update min_time
					dlane[st][tmp.id]=tmp.dis;
					pq.push(tmp);
				}
			}
		}else{
			if(t.dis>dlane[st][t.id]){
				continue;
			}
			tmp.f=1;
			for(auto&&to:lane[t.id]){//lane to site
				tmp.id=to.first;
				tmp.dis=t.dis+to.second;
				if(tmp.dis<lane_site[tmp.id]){
					lane_site[tmp.id]=tmp.dis;
					pq.push(tmp);
				}
			}
		}
	}
}
inline int rll(){
	int res=0;
	char c=getchar();
	while(c<'0'||c>'9'){
		c=getchar();
	}
	while('0'<=c&&c<='9'){
		res=(res<<3)+(res<<1);
		res+=c-'0';
		c=getchar();
	}
	return res;
}
inline void wll(int v){
	if(v==0){
		putchar('0');
		putchar('\n');
		return;
	}
	char tmp[55];
	int cnt=0;
	while(v){
		tmp[cnt]=v%10+'0';
		v/=10;
		++cnt;
	}
	while(cnt--){
		putchar(tmp[cnt]);
	}
	putchar('\n');
}
inline void pred(){
	//cin>>c>>n>>m>>d>>Q;
	c=rll();n=rll();m=rll();d=rll();Q=rll();
	for(int i=1;i<=m;++i){
		dsite[i]=rll();
		//cin>>dsite[i];
		site[i].reserve(d+5);
	}
	int k,a,t;
	for(int i=1;i<=n;++i){
		k=rll();
		//cin>>k;
		lane[i].reserve(k+5);
		while(k--){
			a=rll();t=rll();
			//cin>>a>>t;
			lane[i].push_back(pair<int,int>(a,t));
			site[a].push_back(pair<int,int>(i,t));
		}
		fill(&dlane[i][0],&dlane[i][n+11],LONG_LONG_MAX/4);
	}
}
inline void reply(){
	int st,ed,ans;
	while(Q--){
		st=rll();ed=rll();
		//cin>>st>>ed;
		if(st==ed){
			wll(0);
			//cout<<"0\n";
			continue;
		}
		ans=LONG_LONG_MAX;
		for(auto&&st_lane:site[st]){
			if(dlane[st_lane.first][st_lane.first]==LONG_LONG_MAX/4){
				dij(st_lane.first);
			}
			for(auto&&ed_lane:site[ed]){
				ans=min(ans,dlane[st_lane.first][ed_lane.first]+st_lane.second+ed_lane.second);
			}
		}
		wll(ans+dsite[st]+dsite[ed]);
		//cout<<ans+dsite[st]+dsite[ed]<<'\n';
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0),
	cin.tie(0),cout.tie(0);
	//uniform_int_distribution<int>dist(0,100);
	pred();
	reply();
	return 0;
}
