#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int c,n,m,d,q,res;
int w[N],Map[N][N];
queue<int>qq;
void bfs(int rx,int ry){
	while(!qq.empty()){
			int t=qq.front();
			qq.pop();
			if(Map[t][ry]){
				res+=Map[t][ry];
				cout<<res;
				break;
			}
			for(int i=1;i<=m;i++){
				if(t==i) continue;
				else if(Map[rx][i]){
					res+=Map[rx][i];
					qq.push(i);
					bfs(i,ry);
				}
				res-=Map[rx][i];
			}
		}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int a,t;
			cin>>a>>t;
			Map[i][a]=Map[a][i]=t;
		}
	}
	while(q--){
		int rx,ry;
		cin>>rx>>ry;
		res=w[rx]+Map[rx][rx]+w[ry];
		qq.push(rx);
		bfs(rx,ry);
	}
}