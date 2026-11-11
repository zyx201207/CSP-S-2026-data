#include<bits/stdc++.h>
using namespace std;
int n,k;
vector<int> e[60000];
int vis[60000];
queue<pair<int,int> > q;
int dfs(int s,int v,int p){
	int cnt=0;
	while(q.size()){
		auto f=q.front();
		int i=f.first,r=f.second;
		q.pop();
		if(vis[i])continue;
		vis[i]=p;
		cnt++;
		for(int to:e[i]){
			if(r<v)q.push({to,r+1});
		}
	}
	return cnt;
}
bool check(int v){
	int ans=0;
	for(int i=1;i<=n;i++){
		int cnt=0;
		for(int j=1;j<=n;j++)vis[j]=0;
		if(v%2==0){
			q.push({i,0});
			cnt=dfs(i,v,1);
			//cout<<cnt<<' '<<v<<endl;
			for(int j=1;j<=n;j++){
				ans=max(ans,cnt+dfs(j,v,2));
				for(int l=1;l<=n;l++)if(vis[l]==2)vis[l]=0;
			}
		}else{
			for(int jj:e[i]){
				for(int l=1;l<=n;l++)vis[l]=0;
				cnt=0;
				q.push({i,0});
				q.push({jj,0});
				cnt=dfs(i,v-1,1);
				//cout<<cnt<<' '<<v<<endl;
				for(int j=1;j<=n;j++){
					ans=max(ans,cnt+dfs(j,v,2));
					for(int l=1;l<=n;l++)if(vis[l]==2)vis[l]=0;
				}
			}
		}
	}
	//cout<<ans<<endl;
	if(ans>=k)return true;
	else return false;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<n;i++){
			int xx,yy;
			cin>>xx>>yy;
			e[xx].push_back(yy);
			e[yy].push_back(xx);
		}
		int l=0,r=n;
		while(l+1<r){
			int mid=(l+r)>>1;
			if(check(mid))r=mid;
			else l=mid;
		}
		cout<<r<<'\n';
		for(int i=1;i<=n;i++){
			e[i].erase(e[i].begin(),e[i].end());
		}
	}
}
