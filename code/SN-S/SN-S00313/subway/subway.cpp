//已经退役一年了，过来凑个数。 75+40+？ 能到吗？
//几年OI也是学了个寂寞...... 我仍然在无人问津的阴雨霉湿之地 ......


#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll maxn=15000;
struct way{
	ll to,dis=0;
};

struct node{
	ll num;
	bool vis=0;
	ll type=0;
	ll min_dis=1e18+7;
	vector <way> next_stop;
};


ll test_id,lines,platforms,transfers,query;

node node_list[maxn];
vector <ll> anses[maxn];

ll get_idx(ll type,ll idx){
	if (type==1){
		return idx;
	}
	if (type==2){
		return idx + platforms;
	}
	if (type==3){
		return idx + platforms*2;
	}
}
//1 entry
//2 hall
//3 lines

node init_node(ll type,ll num){
	node ans;
	ans.num=num;
	ans.type=type;
	return ans;
}

void add(ll anum,ll bnum,ll w){
	way way1; way1.dis=w; way1.to=bnum;
	way way2; way2.dis=w; way2.to=anum;
	
//	printf("add anum:%lld bnum:%lld w=%lld\n",anum,bnum,w);
	node_list[anum].next_stop.push_back (way1);
	node_list[bnum].next_stop.push_back (way2);
}

queue <node> q;
ll final_nums;

void clear_node(){
	while (!q.empty()) q.pop();
	for (ll i=1;i<=final_nums;i++){
		node_list[i].vis=0;
		node_list[i].min_dis=1e18+7;
	} 
}

void solve(ll l){
	clear_node();
	node_list[get_idx(1,l)].vis=1;
	node_list[get_idx(1,l)].min_dis=0;
	
	q.push(node_list[get_idx(1,l)]);
	
	
	while (!q.empty()){
		node now=q.front();
//		printf("bfs now type:%lld idx:%lld dis=%lld\n",now.type,now.num,now.min_dis);
		q.pop();
		now.vis=1;
		for (way w:now.next_stop){
			if (now.min_dis+w.dis < node_list[w.to].min_dis){
				node_list[w.to].min_dis = now.min_dis+w.dis;
				if (!node_list[w.to].vis){
					q.push(node_list[w.to]);
//					printf("push to type:%lld idx:%lld dis=%lld\n",node_list[w.to].type,node_list[w.to].num,node_list[w.to].min_dis);
					node_list[w.to].vis=1;
				}
			}
			
		}
	}
	
	for (ll i=1;i<=platforms;i++){
		anses[l].push_back(node_list[i].min_dis);
	}
	
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
//
  	ios::sync_with_stdio(0);
  	cin.tie(0);
  	cout.tie(0);
	
	
	cin>>test_id>>lines>>platforms>>transfers>>query;
//	ll entry_nums=0, station_nums=platforms, line_nums=platforms * 2 ;
	
	for (ll i=1;i<=platforms; i++){
		node_list[get_idx(1,i)] = init_node(1,get_idx(1,i));
		node_list[get_idx(2,i)] = init_node(2,get_idx(2,i));
		ll w;
		cin>>w;
		add(get_idx(1,i),get_idx(2,i),w);
	}
	
	for (ll i=1;i<=lines;i++){
		ll goby;
		cin>>goby;
		
		node_list[get_idx(3,i)] = init_node(3,get_idx(3,i));
		
		for (ll j=1;j<=goby;j++){
			ll ai,ti;
			cin>>ai>>ti;
			add(get_idx(3,i),get_idx(2,ai),ti);
		}
	}
	

	final_nums=lines+2*platforms;
	
	for (ll i=1;i<=platforms;i++) solve(i);
	
	while(query--){
		ll l,r;
		cin>>l>>r;
		cout<<min(anses[l][r-1],anses[r][l-1])<<"\n";
		
	}
}


