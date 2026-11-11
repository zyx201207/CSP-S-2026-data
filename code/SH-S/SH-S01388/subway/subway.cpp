#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[500010];
struct node{
	int st,t;
};
struct node2{
	int now,step,l;
};
vector<node>l[550];//第i条线路经过第j个地铁站
//vector<node>s[500010]; 
map<int,map<int,bool>>vis;
map<int,map<int,int>>s;//第i个地铁站可换乘j线路
//vector<int>t[500010];//从i个站厅走到j线路站台 
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;++i){
		cin>>w[i];
	}
	int t;
	for(int i=1;i<=n;++i){
		int k;
		cin>>k;
		for(int j=1;j<=k;++j){
			int a,T;
			cin>>a>>T;
			if(l[i].empty()){
				l[i].push_back({0,0});
			}
			l[i].push_back({a,T});
			t=T;
		}
	}
//	cout<<s[3][2].t<<"\n";
	while(q--){
		int st,ed;
		cin>>st>>ed;
		queue<node2>q;

		for(int i=1;i<=n;++i){
			if(s[st][i]!=0)q.push({st,w[st]+t,i});
			//vis[st][i]=1;
		}
		while(!q.empty()){
			node2 f=q.front();
			q.pop();
			//cout<<f.now<<" "<<f.l<<" "<<f.step<<"\n";
			if(f.now==ed){
				cout<<f.step+t+w[f.now]<<"\n";
				break;
			}
			//cout<<f.l<<" "<<l[f.l].size()<<"\n";
			for(int i=1;i<l[f.l].size();++i){
				//if(vis[l[f.l][i].st][f.l]==0){
					q.push({l[f.l][i].st,f.step,f.l});
					vis[l[f.l][i].st][f.l]=1;
				//}
			}
			int len=s[f.now].size();
			for(int i=1;i<len;++i){
				if(vis[f.now][i]==0){
					q.push({s[f.now][i],f.step+t+t,i});
					vis[f.now][i]=1;
				}
			}
			
		}
	}
	return 0;
}
