#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,qe,t[500005];
struct Edge{
	int g;
	int t[50];
	int v[50];
};
Edge s[500005];
void dj(int ss,int tt){
	priority_queue<pair<int ,pair<int ,int > >,vector<pair<int ,pair<int ,int > > >,greater<pair<int ,pair<int ,int > > > > q;
	int dis[500005];
	memset(dis,0x3f,sizeof(dis));
	for(int i = 1; i <= n; i++){
		q.push({s[ss].t[i],{ss,i}});
	}
	dis[ss] = 0;
	while(q.size()){
		int x = q.top().second.first;
		int time = q.top().first;
		int subway = q.top().second.second;
		q.pop();
		if(x == tt){
			dis[tt] += s[x].t[subway];
			break;
		}
		for(int i = 1; i <= n; i++){
			if(s[x].v[i] == 0)continue;
			int dt = s[x].v[i];
			int now_time;
			if(i == subway){
				now_time = time;
			}else{
				now_time = time + s[x].t[subway] + s[x].t[i];
			}
			if(dis[dt] > now_time){
				dis[dt] = now_time;
				q.push({now_time,{dt,i}});
			}
		}
	}
//	for(int i = 1; i <= m; i++){
//		cout << dis[i] << " ";
//	}
//	cout << endl;
cout << dis[tt] << endl;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> qe;
	for(int i = 1; i <= m; i++){
		cin >> s[i].g;
	}
	for(int i = 1; i <= n; i++){
		int x;
		cin >> x;
		int da,db;
		cin >> da >> db;
		s[da].t[i] = db;
		for(int j = 2; j <= x; j++){
			int a,b;
			cin >> a >> b;
			s[a].t[i]  = b;
			s[da].v[i] = a;
			db = b;
			da = a;
		}
	}
	for(int i = 1; i <= qe; i++){
		int ss,tt;
		cin >> ss >> tt;
		dj(ss,tt);
		
	}
	return 0;
}
