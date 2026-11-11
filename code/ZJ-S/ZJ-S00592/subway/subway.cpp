#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int M=5e5+517;
const int N=517;

int c;
int n,m,d,q;
ll mv[M];

struct station{
	int cnt;
	int subn[23];
	int subv[23];
};
station mp[M];
int cnt[N];// 各个地铁线的站点数 
vector<int> sub[N];
vector<ll > sub_to_v[N];
int st,ed;

vector<ll> v[N];// 在 N 号线上开始的点都到 m 号站厅的步行时间  的最小时间       v[n][m]
                //  建表查询 
int solve(int xn){
	queue<int>q;
	for(int ii=0;ii<cnt[xn];ii++){// xn号线上的点带入 
		q.push(sub[xn][ii]);
		v[xn][sub[xn][ii]]=sub_to_v[xn][ii];
	}
	while(!q.empty()){
		station xx=mp[q.front()];
		int xx_num=q.front();
		q.pop();
		for(int i=1;i<=xx.cnt;i++){//遍历线路 
			for(int j=0;j<cnt[xx.subn[i]];j++){//遍历线路上的节点 
				ll yy=v[xn][xx_num]   +   xx.subv[i]+sub_to_v[xx.subn[i]][j];//从 xx 通过 下标为 i 的线路到达 线路上下标为 j 的步行时间 
				if(v[xn][ sub[xx.subn[i]][j] ] > yy){
					q.push( sub[xx.subn[i]][j] );
					v[xn][ sub[xx.subn[i]][j] ]=yy;
				}
			}
		}
	}
	return 0;
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>mv[i];
	}
	for(int i=1;i<=n;i++){
		ll kk;
		cin>>kk;
		for(int j=1;j<=kk;j++){
			int numk=0,numv=0;
			cin>>numk>>numv;
			cnt[i]++;
			sub[i].push_back(numk);
			sub_to_v[i].push_back(numv);
			mp[numk].cnt++;
			int tt=mp[numk].cnt;
			mp[numk].subn[tt]=i;
			mp[numk].subv[tt]=numv;
		}
		for(int j=0;j<=m;j++){
			v[i].push_back(1e18);
		}
	}

	for(int i=1;i<=n;i++){//建表 
		solve(i);
	}
	
	for(int i=1;i<=q;i++){// o(d)查询（大概？） 
		cin>>st>>ed;
		station xx=mp[st];
		ll ans1=1e18;
		for(int j=1;j<=xx.cnt;j++){
			ans1=min(ans1,mv[st]+mv[ed]+v[xx.subn[j]][ed]+xx.subv[j]);
		}
		cout<<ans1<<'\n';;
	}
}


/*
16:48  32分 1~8 
17:26  44分 1~11 为什么   TLE！！！！！ 
*/
