#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll w[500002];
int k[502];
ll trns[502][502];
ll dis[502][502];
vector<pair<int,ll> >b[500002]; 
vector<pair<int,ll> >tmp;//toline,cost
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	//pass pretask at 16:40
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	
	for(int i=0;i<=n;i++){
		for(int j=0;j<=n;j++){
			trns[i][j]=trns[j][i]=1e12;
			dis[i][j]=1e12;
		}
	}
//	memset(trns,0x3f,sizeof(trns));
	
	for(int i=1;i<=n;i++){
		trns[i][i]=0;
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			int ft,sc;
			cin>>ft>>sc;
			b[ft].push_back({i,sc});
		}
	}
	
	for(int i=1;i<=m;i++){
		for(auto j:b[i]){
			for(auto z:b[i]){
			//	if(j.first==z.first)continue;
				if(trns[j.first][z.first]>j.second+z.second){
			//		cout<<j.second+z.second<<"!\n";
					trns[j.first][z.first]=trns[z.first][j.first]=j.second+z.second;
				}
			}
		}
	}
	
	priority_queue<pair<ll,int> >pq;//-dis, idx
	for(int i=1;i<=n;i++){
		while(pq.size())pq.pop();
	
		pq.push({0,i});
		dis[i][i]=0;
		while(!pq.empty()){
			auto p=pq.top();
			pq.pop();
			for(int j=1;j<=n;j++){
				if(i==j)continue;
				if(trns[j][p.second]==1e12){//not approach
			//	cout<<"!";
					continue;//It shall never happen
				}
				if(dis[i][j]>-p.first+trns[p.second][j]){
					dis[i][j]=dis[j][i]=-p.first+trns[p.second][j];
					pq.push({-dis[i][j],j});
				}
			}
		}
	}
	
/*	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cout<<i<<" "<<j<<" : "<<dis[i][j]<<" ";
		}
		cout<<"\n";
	}
*/	
	
	
	while(q--){
		int x,y;
		cin>>x>>y;
		ll minn=dis[0][0];
		for(auto i:b[x]){
			for(auto j:b[y]){
		/*		if(i.second+j.second+dis[i.first][j.first]<minn){
					;
				}else{
					cout<<dis[i.first][j.first]<<"W";
				}*/
				minn=min(minn,i.second+j.second+dis[i.first][j.first]);
			}
		}
		cout<<minn+w[x]+w[y]<<"\n";
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

*/
/*
看这里！
SH-J01467陈润禾小朋友 你的文件夹命名出错了 不应在准考证号和姓名全拼中添加空格
ccf ccf ccf ccf ccf ccf ccf ccf ccf ccf ccf ccf ccf ccf ccf ccf ccf ccf ccf ccf ccf ccf ccf ccf ccf ccf ccf ccf ccf ccf ccf ccf ccf ccf ccf ccf ccf ccf ccf ccf ccf ccf ccf ccf ccf ccf ccf ccf ccf ccf ccf ccf ccf ccf ccf 
AFO AFO AFO AFO AFO AFO AFO AFO AFO AFO
*/

