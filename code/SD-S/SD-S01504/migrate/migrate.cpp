#include<bits/stdc++.h>
using namespace std;
int n,m,q,ccc,a[100005],ans,cnt[300][300][300],d[300][10005];
vector<int>v[100005];
void bfs(int x){
	queue<pair<int,int> >q;
	q.push({x,0});
	
	while(q.size()){
		auto p=q.front();
		q.pop();
		for(auto i:v[p.first]){
			d[x][i]=min(d[x][i],p.second+1);
			cnt[x][i][p.second+1]++;
			q.push({i,p.second+1});
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
freopen("migrate.out","w",stdout);
cin>>ccc>>q;
while(q--){
	for(int i=1;i<=n;i++){
		if(v[i].size()){
		
		v[i].clear();
		}for(int j=1;j<=n;j++){
			//cout<<d[i][j]<<" ";
			d[i][j]=2e9;
			for(int k=1;k<=n;k++){
				cnt[i][j][k]=0;
			}
		}
	}
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}for(int i=1;i<=n;i++){
		for(int j=i-1;j>=1;j--){
			if(a[i]-a[j]<=m){
				v[j].push_back(i);
			}else{
				break;
			}
		}
	}for(int i=1;i<=n;i++){
		bfs(i);
	}for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(cnt[i][j][d[i][j]>n?0:d[i][j]]==2){
				ans++;
			}
		}
	}
	cout<<ans<<'\n';
	
}
	return 0;
}

