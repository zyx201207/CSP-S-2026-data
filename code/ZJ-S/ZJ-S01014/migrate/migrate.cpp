#include<bits/stdc++.h>
using namespace std;
int n,d;
int c,t;
bool in[200001]={0};
int cnt[200001]={0};
int dis[200001]={0};
long long a[200001];
vector<int> g[200001];
int bfs(int st){
	int res=0;
	memset(dis,0x3f,sizeof(dis));
	memset(cnt,0,sizeof(cnt));
	queue<int> q;
	q.push(st);
	dis[st]=0;
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(int v:g[u]){
			if(v<=u){
				continue;
			}
			if(dis[v]==0x3f3f3f3f){
				cnt[v]++;
				//cout<<78<<endl;
				dis[v]=dis[u]+1;
				if(!in[v]){
					in[v]=true;
					q.push(v);
				}
				//cout<<91<<' '<<u<<' '<<v<<' '<<dis[v]<<endl;
				//cout<<13<<' '<<v<<endl;
				continue;
			}else if(dis[u]+1==dis[v]){
				//if(v!=st+1){
					cnt[v]++;
				//}
				//cout<<78<<' '<<u<<' '<<v<<' '<<dis[v]<<endl;
				//q.push(v);
				//cout<<91<<' '<<v<<endl;
			}
		} 
	}
	//cout<<st<<endl;
	for(int i=1;i<=n;i++){
		if(cnt[i]==2){
			res++;
		}
		//cout<<cnt[i]<<' ';
	}
	//cout<<endl;
	return res;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		int ans=0;
		cin>>n>>d;
		//cin>>a[1];
		for(int i=1;i<n;i++){
			cin>>a[i];
			//g[i].push_back(i-1);
			g[i].push_back(i+1);
		}
		cin>>a[n];
		//g[1].push_back(2);
		//g[n].push_back(n-1);
		for(int i=1;i<=n;i++){
			/*for(int j=i-2;j>=1;j--){
				if(abs(a[i]-a[j])<=d){
					g[i].push_back(j);
				}
			}*/
			for(int j=i+2;j<=n;j++){
				if(abs(a[j]-a[i])<=d && j!=i+1){
					g[i].push_back(j);
				}
			}
		}
		for(int i=1;i<=n;i++){
			ans+=bfs(i);
		}
		cout<<ans<<'\n';
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
