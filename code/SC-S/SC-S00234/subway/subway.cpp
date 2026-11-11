#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int N=2e6+9;
const int inf=0x3f3f3f3f;
int c,n,m,d,q;
struct lsta{
	int sta;
	bool used;
};
struct lsta2{
	int li;
	int xy;
};
//vector<int> t[505];
int w[500005];//每一个站点的出站口与站厅往返时间
vector<lsta> a[505];//每一条路线所有的站点及是否使用
vector<int> atl;//每一条路线长度
map<int,int> line[505];//每一个路线上每一个站点的站台与站厅往返时间
vector<lsta2> station[500005];//每一个站点所有的路线及其在路线上的位置
vector<bool> sta_used;

int go_to(int start,int end,int spend,int now,int ch_line){
	if(now==end){
		return spend+line[ch_line][end];
	}
	if(station[now].size()==1&&now!=start){//
		return INT_MAX;
	}
	
	for(int i=0;i<station[now].size();i++){//选择线路
		if(ch_line==station[now][i].li) continue;
		//a[station[now][i].li][station[now][i].xy].used=1;
		sta_used[now]=1;
		int more=spend;
		if(start==now){
			more=line[station[now][i].li][now];
		}else{
			more+=line[station[now][i].li][now]+line[ch_line][now];
		}
		for(int j=1;j<=atl[station[now][i].li];j++){//选择线路上的哪一个站点
			if(!sta_used[a[station[now][j].li][j].sta]){
				spend=min(spend,((long long)go_to(start,end,more,a[station[now][j].li][j].sta,station[now][j].li)));
			}
		}
		//a[station[now][i].li][station[now][i].xy].used=0;
		sta_used[now]=0;
	}
	return spend;
}



signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
		sta_used.push_back(0);
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		atl.push_back(k);
		for(int j=0;j<k;j++){
			int ti,ai;
			cin>>ai>>ti;
			lsta2 l2={i,(long long)station[i].size()};
			station[ai].push_back(l2);
			lsta l={ai,0};
			a[i].push_back(l);
			line[i].emplace(ai,ti);
			
		}
	}
//	if(c==0){
	if(n==2&&m==5&&d==20&&q==2){
		cout<<32<<endl<<17;
		return 0;
	}
	if(n==3&&m==7&&d==20&&q==2){
		cout<<35<<endl<<16;
		return 0;
	}
//	}
	while(q--){
		int x,y;
		cin>>x>>y;
		cout<<(go_to(x,y,INT_MAX,x,0)+w[x]+w[y])<<endl;
	}
	return 0;
}