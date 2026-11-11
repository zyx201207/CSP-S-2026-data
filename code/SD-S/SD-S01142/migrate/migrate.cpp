#include<bits/stdc++.h>
using namespace std;
const int N=5010;
typedef long long ll;
int c,T;
int n;
ll d;
ll a[N];
vector<int> mv[N];//第i个能走到的岛屿所在下标  
ll dis[N];//第i座岛屿访问时总步数
void dfs(int u,int v,ll &min_dis){
	//cout<<"u="<<u<<endl;
	if(u==v){
		if(min_dis>=dis[v]){
			//cout<<"???";
			min_dis=dis[v];
			//cout<<"min_dis="<<min_dis<<endl;
		}
		return;
	}
	for(int i=0;i<mv[u].size();i++){
		int ne=mv[u][i];
		dis[ne]=dis[u]+1;
		if(ne<=v) dfs(ne,v,min_dis);
	}
} 
void dfs1(int u,int v,ll min_dis,int &cnt){
	//cout<<"hhu="<<u<<endl;
	if(u==v){
		if(min_dis==dis[v]){
			cnt++;
		}
		return;
	}
	
	for(int i=0;i<mv[u].size();i++){
		//cout<<"i="<<i<<" x="<<mv[u][i]<<endl;
		int ne=mv[u][i];
		if(ne<=v){
			//cout<<"ne="<<ne<<endl;
			dis[ne]=dis[u]+1;
			dfs1(ne,v,min_dis,cnt);
			//cout<<"bne="<<ne<<endl;
			//cout<<"bi="<<i<<endl;
		}
	}
}
int ans;
void solve(int u,int v){
	ll min_dis=LLONG_MAX; 
	int cnt=0;
	dfs(u,v,min_dis);
	//cout<<"u="<<u<<" v="<<v<<" min_dis="<<min_dis<<endl;
	for(int i=1;i<=n;i++) dis[i]=0;
	dfs1(u,v,min_dis,cnt);
	//cout<<"cnt="<<cnt<<endl;
	if(cnt==2) ans++;
}
/*0 2
4 2
1 2 3 4
5 2
1 2 3 4 5
*/
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>T;
	while(T--){
		ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			mv[i].clear();
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(a[j]-a[i]<=d){
					//cout<<"i="<<i<<" j="<<j<<endl;
					mv[i].push_back(j);
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				solve(i,j);
				for(int i=1;i<=n;i++) dis[i]=0;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

