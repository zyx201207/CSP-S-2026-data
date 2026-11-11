#include<bits/stdc++.h>
using namespace std;
#define int long long
pair<int,int> u;
int dis,nex,c,n,m,k[500005],d,ask,w[500005],a,x,y,t[500005],ans[500005];
vector< pair<int,int> > v[500005];
priority_queue<pair<int,int>,vector< pair<int,int> >,greater< pair<int,int> > > q;
//bool b[500005][600];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>ask;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[0];
		for(int j=1;j<=k[0];j++){
			cin>>k[j]>>t[j];
			for(int o=1;o<j;o++){
				v[k[o]].push_back(make_pair(t[o]+t[j],k[j]));
				v[k[j]].push_back(make_pair(t[j]+t[o],k[o]));
			}
			//b[a][i]=1;
			
		}
	}
	/*for(int i=1;i<=m;i++){
		for(int j=0;j<v[i].size();j++){
			cout<<i<<"->"<<v[i][j].second<<":"<<v[i][j].first<<endl;
		}
	}*/
	for(int i=1;i<=ask;i++){
		cin>>x>>y;
		//ans=1e18;
		//q.clear();
		memset(ans,0x3f,sizeof(ans));
		ans[x]=0;
		q.push(make_pair(0,x));
		while(!q.empty()){
			u=q.top();
			dis=u.first;nex=u.second;
			q.pop();
			if(dis>ans[nex]) continue;
			for(int j=0;j<v[nex].size();j++){
				if(ans[v[nex][j].second]>ans[nex]+v[nex][j].first){
					ans[v[nex][j].second]=ans[nex]+v[nex][j].first;
					q.push(make_pair(ans[v[nex][j].second],v[nex][j].second));
				}
			}
		}
		cout<<ans[y]+w[x]+w[y]<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
