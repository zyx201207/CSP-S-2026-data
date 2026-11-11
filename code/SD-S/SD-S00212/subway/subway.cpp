#include <bits/stdc++.h>
using namespace std;
long long w[500010],dis[500010][2],tim[500010];
int st[500010];
vector<vector<pair<int,int>>>v(500010);
bool isinque[500010];
long long spfa(int st,int en){
	dis[st][0]=dis[st][1]=w[st]+w[en]+tim[st]+tim[en];
	queue<pair<int,int>>q;
	map<int,int>mp;
	for(auto it:v[st]){
		if(!mp.count(it.second))q.push({st,it.second}),mp[it.second]=1;
		isinque[st]=1;
		while(!q.empty()){
			pair<int,int>t=q.front();
			q.pop();
			isinque[t.first]=0;
			if(t.first==en)return min(dis[en][1],dis[en][0]);
			for(auto it:v[t.first]){
				if(t.second!=it.second){
					long long h=dis[t.first][1]+tim[t.first]+tim[it.first];
					long long b=dis[t.first][0]+tim[t.first]+tim[it.first];
					if(h<b&&h<dis[it.first][1]){
						dis[it.first][1]=h;
						if(!isinque[it.first]){
							q.push({it.first,it.second});
							isinque[it.first]=1;
						}
					}else if(b<h&&b<dis[it.first][1]){
						dis[it.first][1]=b;
						if(!isinque[it.first]){
							q.push({it.first,it.second});
							isinque[it.first]=1;
						}
					}else if(b==h&&h<dis[it.first][1]){
						dis[it.first][1]=b;
						if(!isinque[it.first]){
							q.push({it.first,it.second});
							isinque[it.first]=1;
						}
					}
				}else{
					long long h=dis[t.first][1]+tim[t.first]+tim[it.first];
					long long b=dis[t.first][0]+tim[t.first]+tim[it.first];
					if(h<b&&h<dis[it.first][0]){
						dis[it.first][0]=h;
						if(!isinque[it.first]){
							q.push({it.first,it.second});
							isinque[it.first]=1;
						}
					}else if(b<h&&b<dis[it.first][0]){
						dis[it.first][0]=b;
						if(!isinque[it.first]){
							q.push({it.first,it.second});
							isinque[it.first]=1;
						}
					}else if(b==h&&h<dis[it.first][0]){
						dis[it.first][0]=b;
						if(!isinque[it.first]){
							q.push({it.first,it.second});
							isinque[it.first]=1;
						}
					}
				}
			}
		}
	}
	return min(dis[en][1],dis[en][0]);
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;cin>>k;
		cin>>st[1];cin>>tim[st[1]];
		for(int j=2;i<=k;j++){
			cin>>st[j];cin>>tim[st[j]];
			v[st[j]].push_back({st[j-1],i});
			v[st[j-1]].push_back({st[j],i});
		}
	}
	while(q--){
		int x,y;cin>>x>>y;
		cout<<spfa(x,y)<<"\n";
	}
	return 0;
}
