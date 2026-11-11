#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,next[510][510],next_num[510],q,w[500010],k,to_num[500010],to[500010][25][2],way[510][510],Time[510][510];
queue<long long> q_from,q_to,q_time;
//to下标0为线路，下标1为时间 
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			int locate,t;
			cin>>locate>>t;
			to_num[locate]++;
			to[locate][to_num[locate]][0]=i;
			to[locate][to_num[locate]][1]=t;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j){
				continue;
			}
			Time[i][j]=1e18;
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<to_num[i];j++){
			for(int l=j+1;l<=to_num[i];l++){
				if(way[to[i][j][0]][to[i][l][0]]==0||way[to[i][j][0]][to[i][l][0]]>to[i][j][1]+to[i][l][1]){
					way[to[i][j][0]][to[i][l][0]]=to[i][j][1]+to[i][l][1];
					way[to[i][l][0]][to[i][j][0]]=to[i][j][1]+to[i][l][1];
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j){
				continue;
			}
			if(way[i][j]==0){
				continue;
			}
			next_num[i]++;
			next[i][next_num[i]]=j;
			next_num[j]++;
			next[j][next_num[j]]=i;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=next_num[i];j++){
			if(Time[i][next[i][j]]<=way[i][next[i][j]]){
				continue;
			}
			q_from.push(i);
			q_to.push(next[i][j]);
			q_time.push(way[i][next[i][j]]);
		}
		while(!q_from.empty()){
			long long now_from=q_from.front(),now_to=q_to.front(),now_time=q_time.front();
			q_time.pop();
			q_to.pop();
			q_from.pop();
			if(Time[i][now_to]>Time[i][now_from]+now_time){
				Time[i][now_to]=Time[i][now_from]+now_time;
				Time[now_to][i]=Time[i][now_from]+now_time;
				for(int j=1;j<=next_num[now_to];j++){
					if(Time[i][next[now_to][j]]>Time[i][now_to]+way[now_to][next[now_to][j]]){
						q_from.push(now_to);
						q_to.push(next[now_to][j]);
						q_time.push(way[now_to][next[now_to][j]]);
					}
				}
			}
		}
	}
	/*for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cout<<Time[i][j]<<" "; 
		}
		cout<<endl;
	}*/
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		long long ans=1e18;
		for(int j=1;j<=to_num[x];j++){
			for(int l=1;l<=to_num[y];l++){
				ans=min(ans,Time[to[x][j][0]][to[y][l][0]]+to[x][j][1]+to[y][l][1]+w[x]+w[y]);
				//cout<<Time[to[x][j][0]][to[y][l][0]]<<" "<<to[x][j][1]+to[y][l][1]<<" "<<w[x]+w[y]<<endl;
				//cout<<ans<<endl;
			}
		}
		cout<<ans<<endl;
		//cout<<endl;
	}
	return 0;
}

