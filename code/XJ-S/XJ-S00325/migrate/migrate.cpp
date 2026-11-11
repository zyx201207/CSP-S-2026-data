#include<bits/stdc++.h>
using namespace std;
const int N=305;
int c,t,tot=0,ed=0;
long long dis[N];
int depth[N];
vector<int>vec[N];
int bfs(int bg,int lst){
	vector<int>v;
	v.resize(N);
	vector<int>ans;
	ans.resize(N);
	queue<int>q;
	q.push(bg);
	ans[bg]=1;
	while(q.size()){
		int u=q.front();
		q.pop();
		for(auto x:vec[u]){
			if(x==bg) continue;
			if(v[u]+1>=v[x]&&v[x]!=0){
				ans[x]+=(v[u]+1==v[x]);
				continue;
			}
			ans[x]=1;
			v[x]=v[u]+1;
			q.push(x);
		}
	}
//	cout<<" "<<bool(ans[lst-tot]==2)<<"\n";
//	cout<<"a bfs\n";
	if(ans[lst]==2) return 1;
	return 0;
}
int main(){
//	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		int n,d,ans=0;
		cin>>n>>d;
		tot=ed+1;
		ed=tot+n-1;
		for(int i=tot;i<=ed;i++){
			cin>>dis[i];
			for(int j=tot;j<i;j++){
				if(abs(dis[i]-dis[j])<=d){
					vec[i].push_back(j);
					vec[j].push_back(i);
				}
			}
		}
//		for(int i=tot;i<=ed;i++){
//			cout<<i<<"\n";
//			for(auto gh:vec[i]){
//				cout<<gh<<" ";
//			}
//			cout<<"\n";
//		}
		for(int i=tot;i<=ed;i++){
			for(int j=tot;j<i;j++){
				ans+=bfs(j,i);
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
} 
