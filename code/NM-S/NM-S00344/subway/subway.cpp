#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500005],ans=INT_MAX;
vector<pair<int,int> >a[50005];
void bfs(int s,int e){
	queue<pair<int,int> >q;
	q.push({s,0});
	while(!q.empty()){
		int u=q.front().first,step=q.front().second;q.pop();
		cout<<u<<" "<<step<<endl;
		for(auto t:a[u]){
			int v=t.first,ww=t.second;
			cout<<v<<" "<<ww<<endl;
			if(v==e){
                ans=min(ans,step+ww);
                return;
			}else q.push({v,step+ww});
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;cin>>k;
		int a1,a2,b1,b2;cin>>a1>>a2>>b1>>b2;
		a[a1].push_back({b1,a2+b2});
		a[b1].push_back({a1,a2+b2});
	}0
	while(q--){
		int x,y;cin>>x>>y;
		ans=INT_MAX;
		bfs(x,y);
		cout<<ans+w[x]+w[y]<<endl;
	}
	return 0;
}



