#include <bits/stdc++.h>

using namespace std;

int c,t,n,d,x[200006];
int ans = 0;
int gg[200006];

void bfs(int y){
	//cout<<"start"<<y<<endl;
	int dis[200006];
	memset(dis,-1,sizeof dis);
	
	queue<int> q;
	queue<int> fd;
	q.push(y);
	fd.push(0);
	while(!q.empty()){
		int u = q.front();
		int ud = fd.front();
		q.pop();
		fd.pop();
		//cout<<"new!"<<u<<" "<<ud<<" "<<endl;
		for(int i = u+1;i <= n;i++){
			if(x[i] > (x[u]+d)) break;
			//cout<<i<<"check"<<dis[i]<<" "<<ud+1<<" "<<gg[i]<<endl;
			if((dis[i]==ud+1)&&(dis[i]!=-1)){
				//cout<<"intoooooo"<<gg[i]<<endl;
				if(gg[i]==0){
					gg[i] = 1;
					ans++;
					//cout<<"new answer!!!"<<i<<endl;
				}
				else if(gg[i]==1){
					gg[i] = 2;
					ans--;
					//cout<<"noooooooooooooo"<<i<<endl;
				}
			}
			dis[i] = ud+1;
			q.push(i);
			fd.push(ud+1);
			//cout<<u<<"come to!"<<i<<" "<<dis[i]<<endl;
		}
		
		//cout<<"wowowowowowowowow!"<<u<<" "<<dis[u]<<endl;
	}
}

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	cin>>c>>t;
	for(int zzz = 0;zzz < t;zzz++){
		//memset(gg,0,sizeof gg);
		ans = 0;
		cin>>n>>d;
		for(int i = 1;i <= n;i++){
			cin>>x[i];
		}
		
		for(int i = 1;i <= n;i++){
			//cout<<"resetttttttttttttt";
			for(int j = 0;j <= n;j++){
				//cout<<gg[j];
				if(gg[j] == 2){
					gg[j] = 0;
					//cout<<22222222222222222;
				}
				if(gg[j] == 1){
					gg[j] = 3;
				} 
			}
			
			bfs(i);
		}
		cout<<ans<<endl;
		//cout<<endl;
	}
	
	
	return 0;
} 
