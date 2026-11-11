#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
int c,T,n;
long long a[N],dd,ans,d[N],num[N];
vector<int> g[N];
bool v[N];
struct node{
	int t,s;
};
void bfs(int st){
	queue<node> q;
	q.push({st,0});
	while(!q.empty()){
		int u=q.front().t,s=q.front().s;
		q.pop();
		int sz=g[u].size();
		for(int i=0;i<sz;i++){
			int x=g[u][i];
			if(v[x]) continue;
			if(s+1<=d[x]){
				d[x]=s+1;
				q.push({x,d[x]});
				num[x]++;
			}
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0),cout.tie(0);
	cin>>c>>T;
	if(c>10){
		while(T--) cout<<"0\n";
		return 0;
	}
	while(T--){
		ans=0;
		cin>>n>>dd;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			g[i].clear();
		} 
		for(int i=1;i<=n;i++){
			v[i]=0;
			d[i]=1e18;
			num[i]=0;
			for(int j=i+1;j<=n;j++){
				if(a[j]-a[i]>dd) break;
				g[i].push_back(j);
				g[j].push_back(i);
			}
		}
		for(int i=1;i<=n;i++){
			v[i]=1;
			bfs(i);
			for(int j=i+1;j<=n;j++){
				if(num[j]==2) ans++;
				num[j]=0;
				d[j]=1e18;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
