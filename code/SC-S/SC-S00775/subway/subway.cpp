#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int M=500005,N=505;
int w[M];
vector<pair<int,int> >a[N];
vector<int>b[M];//表示每一个地铁站有那些地铁可通过 
int vis1[M],vis2[N];
int ans[M];
priority_queue<pair<ll,int> >que;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int c,n,m,d,q;
	cin >> c >> n >> m >> d >> q;
	for(int i=1;i<=m;i++) cin >> w[i];
	for(int i=1;i<=n;i++){
		int k;
		cin >> k;
		for(int j=1;j<=k;j++){
			int aa,tt;
			cin >> aa >> tt;
			a[i].push_back(make_pair(aa,tt));
			b[aa].push_back(i);
		}
	}
	while(q--){
		int x,y;
		cin >> x >> y;
		que.push(make_pair(0,x));
		while(!que.empty()){
			int nowpos=que.top().second,dis=-(que.top().first);que.pop();
			if(vis1[nowpos]) continue;
			vis1[nowpos]=1;
			ans[nowpos]=dis;	
			
			for(int i=0;i<b[nowpos].size();i++){
				int sid=b[nowpos][i];//地铁编号 
				if(vis2[sid]) continue;
				vis2[sid]=1;
				int xx=0;
				for(int j=0;j<a[sid].size();j++){
					if(a[sid][j].first==nowpos) xx=a[sid][j].second;
				}
				for(int j=0;j<a[sid].size();j++){
					if(!vis1[a[sid][j].first])
						que.push(make_pair(-ans[nowpos]-a[sid][j].second-xx,
						a[sid][j].first));
				}
			}
		}
		cout << ans[y]+w[x]+w[y]<<'\n';
		for(int i=1;i<=m;i++) vis1[i]=0;
		for(int i=1;i<=n;i++) vis2[i]=0;
	}
	return 0;
}