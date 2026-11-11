#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,q,w[323232],k[323232],To[323232],l[323232];
vector<pair<int,int>>sb[323232];//subway Nodes
vector<pair<int,int>>G[323232];//Node[x] -> ...
vector<int>zt[323232];//zt[x] Has Subway ...
map<pair<int,int>,int> mp;
struct Node{
	int ans,id,trainid,ChosedTr;//Answer,Station ID,Train ID,Chosen Subway
	bool operator<(Node b)const{
		return ans<b.ans;
	}
//	Node(){}
//	Node(int a,int b,int c){
//		ans=a,id=b,trainid=c;
//	}
};
bool vis[323232];
inline int work(int x,int y){
	int ans=w[x]+w[y];
	for(int i=1;i<=m;i++) vis[i]=0,To[i]=LLONG_MAX;
	To[x]=0;
	priority_queue<Node> l;
	Node ls;
	for(int i=0;i<zt[x].size();i++) l.push({mp[{zt[x][i],x}],x,zt[x][i],i});
	while(l.size()){
		Node h=l.top();
		l.pop();
//		if(vis[h.id]) continue;
		if(h.id==y){
//			cout<<"return ans:"<<mp[{zt[x][h.ChosedTr],x}]<<'\n';
			return h.ans+ans+mp[{h.trainid,h.id}];//Station times+Outstation Time+Plantform(Ending)Times+Plantform(Starting)Times
		}
		for(int i=0;i<G[h.id].size();i++){//Node ID
			for(int j=0;j<zt[G[h.id][i].first].size();j++){//Subway ID
//				cout<<"Report!Now we are in the station #"<<h.id<<",Plantform Subway"<<h.trainid<<";\n";
//				if(zt[G[h.id][i].first][j]==h.trainid&&To[G[h.id][i].first]>To[h.id]){
//					To[G[h.id][i].first]=To[h.id],
//					l.push({h.ans,G[h.id][i].first,
//					h.trainid,h.ChosedTr});
////					cout<<"Next we will go to the next stop!Now time:"<<ans<<" With Number "<<G[h.id][i].first<<" ,Train Code:"<<h.trainid<<"!\n";
//				}else if(zt[G[h.id][i].first][j]!=h.trainid&&To[G[h.id][i].first]>To[h.id]){
//					To[G[h.id][i].first]=To[h.id],
//					l.push({h.ans//Lastly Answer
//					+mp[{zt[G[h.id][i].first][j],h.id}]
//					+mp[{h.trainid,h.id}]
//					,G[h.id][i].first
//					,zt[G[h.id][i].first][j]
//					,h.ChosedTr});
////					cout<<"Next we will transport from Train ID "<<h.trainid<<" to "<<zt[G[h.id][i].first][j]<<";With Using Time"<<mp[{zt[G[h.id][i].first][j],h.id}]
////					+mp[{h.trainid,h.id}]<<"!\n";
//				}
				if(To[G[h.id][i].first]>To[h.id]){
					if(zt[G[h.id][i].first][j]==h.trainid){
						To[G[h.id][i].first]=To[h.id];//Taken
						l.push({h.ans,G[h.id][i].first,h.trainid,h.ChosedTr});//Next stop(One Stop)
					}
					else{
						To[G[h.id][i].first]=To[h.id];//Taken
						l.push({h.ans//Recent Answer
						+mp[{zt[G[h.id][i].first][j],h.id}]//Plantform(New Subway->Station)
						+mp[{h.trainid,h.id}]//Plantform(Old Subway->Station)
						,G[h.id][i].first,//Next Stop
						zt[G[h.id][i].first][j],//New train ID
						h.ChosedTr});
					}
				}
			}
		}
	}
	return 0;
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		cout<<i<<' '<<k[i]<<'\n';
		for(int j=1;j<=k[i];j++){
			int a,b;
			cin>>a>>b;
			mp[{i,a}]=b;//k[i]'s Road With Number A -> Time: b
//			cout<<"Train "<<k[i]<<" To "<<a<<" Needs:"<<b<<'\n';
//			ki[a].push_back(b);
			sb[i].push_back({a,b});
			zt[a].push_back(i);
		}
		for(int j=1;j<sb[i].size();j++){
			G[sb[i][j-1].first].push_back({sb[i][j].first,i});
			G[sb[i][j].first].push_back({sb[i][j-1].first,i});
		}
	}
	for(int i=1;i<=q;i++){
		int a,b;
		cin>>a>>b;
		cout<<work(a,b)<<'\n';
	}
	return 0;
}
