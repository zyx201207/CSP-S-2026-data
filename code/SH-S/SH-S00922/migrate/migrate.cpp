#include<bits/stdc++.h>
using namespace std;
const int N=5e4+5;
#define int long long
typedef pair<int,int> pii;
int c,t;
int n,d;
int a[N];
vector<int> e[N];
int vis[N],deep[N],cnt[N];
int bfs(int s){
	memset(vis,0,sizeof(vis));
	memset(deep,0x3f,sizeof(deep));
	memset(cnt,0,sizeof(cnt));
	queue<pii> q;
	q.push({s,0});
	while(!q.empty()){
		int u=q.front().first,dep=q.front().second;
		q.pop();
		if(dep<=deep[u]){
			deep[u]=dep;
			cnt[u]++;
		}
		if(vis[u])	continue;
		vis[u]=1;
		for(int v:e[u]){
			q.push({v,dep+1});
		}
	}
	int sum=0;
	for(int i=1;i<=n;i++){
		if(cnt[i]==2&&s<i){
			sum++;
		}
	}
	return sum;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++)	cin>>a[i];
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(a[j]-a[i]<=d){
					e[i].push_back(j);
					e[j].push_back(i);
				}
			}
		}
//		for(int i=1;i<=n;i++){
//			cout<<i<<" ";
//			for(int j:e[i]){
//				cout<<j<<" ";
//			}
//			cout<<endl;
//		}
		int ans=0;
		for(int i=1;i<=n;i++){
			ans+=bfs(i);
		}
		cout<<ans<<endl;
		for(int i=1;i<=n;i++)	e[i].clear();
	}
	fclose(stdin);
	fclose(stdout);
//0 1
//7 666666666666666663
//-1000000000000000000 -555555555555555558 -111111111111111116 111111111111111105 333333333333333326 555555555555555547 999999999999999989

	return 0;
}
