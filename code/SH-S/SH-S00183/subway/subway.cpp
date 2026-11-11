#include<bits/stdc++.h>
using namespace std;
struct Station{
	int exit_time;
	vector<pair<int,int>> go_time;
} net[500005];
unsigned int transfer_time[505][505];
bool vis[505];
int c,n,m,d,q,k,s,t,x,y;
unsigned int dfs(int current_line_number,int target_line_number){
	if(current_line_number==target_line_number) return 0;
	unsigned int ans=-1;
	vis[current_line_number]=1;
	for(int i=1;i<=m;i++){
		if(vis[i]==1) continue;
		if(transfer_time[current_line_number][i]!=-1) ans=min(ans,transfer_time[current_line_number][i]+dfs(i,target_line_number));
	}
	return ans;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	memset(transfer_time,-1,sizeof(transfer_time));
	for(int i=1;i<=m;i++){
		cin>>net[i].exit_time;
	}
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>s>>t;
			net[s].go_time.push_back(make_pair(i,t));
			if(net[s].go_time.size()>=2){
				int l=net[s].go_time.size()-1;
				//cout<<s<<" is a transfer station with "<<l+1<<" lines now."<<endl;
				for(int o=0;o<l;o++){
					if(net[s].go_time[o].first==i) continue;
					transfer_time[net[s].go_time[o].first][i]=min((unsigned int)net[s].go_time[o].second+t,transfer_time[net[s].go_time[o].first][i]);
					transfer_time[i][net[s].go_time[o].first]=transfer_time[net[s].go_time[o].first][i];
					//cout<<"Transfer time between "<<net[s].go_time[o].first<<" and "<<i<<" has been updated as "<<transfer_time[net[s].go_time[o].first][i]<<endl;
				}
			}
		}
	}
	while(q--){
		unsigned int ans=-1;
		cin>>x>>y;
		memset(vis,0,sizeof(vis));
		for(int i=0;i<net[x].go_time.size();i++){
			for(int j=0;j<net[x].go_time.size();j++){
				ans=min(ans,dfs(net[x].go_time[i].first,net[y].go_time[j].first)+net[x].go_time[i].second+net[y].go_time[j].second);
			}
		}
		cout<<ans+net[x].exit_time+net[y].exit_time<<endl;
	}
	return 0;
}
