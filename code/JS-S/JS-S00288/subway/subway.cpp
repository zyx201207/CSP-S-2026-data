#include <bits/stdc++.h>
#define int long long
using namespace std;
const int M=5e5+10;
struct T{int x,y,tm;};
int c,n,m,d,q,w[M],a[510][1010],t[510][1010],len[510];
bool vis[510][1010];
int ans,_x,_y,_tm;
void bfs(int s,int e){
	ans=9e18;
	queue<T>q;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=len[i];j++){
			if(a[i][j]==s){
				q.push({i,j,w[s]});
				vis[i][s]=1;
			}
		}
	}
	while(!q.empty()){
		T node=q.front();
		_x=node.x,_y=node.y,_tm=node.tm;
		cout<<_x<<" "<<_y<<" "<<_tm<<endl;
		q.pop();
		if(a[_x][_y]==e){
			ans=min(ans,_tm+w[e]);
		}
		for(int i=1;i<=len[_x];i++){
			if(i==_y) continue;
			for(int j=1;j<=n;j++){
				if(j==_x) continue;
				for(int k=1;k<=len[j];k++){
					if((a[j][k]==a[_x][i]&&vis[j][k]==0)||a[j][k]==e){
						q.push({j,k,_tm+t[_x][_y]+t[_x][i]});
						vis[j][k]=1;
					}
				}
			}
		}
	}
	cout<<ans<<endl;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1,k;i<=n;i++){
		cin>>k;
		len[i]=k;
		for(int j=1;j<=k;j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	while(q--){
		int s,e;
		cin>>s>>e;
		cout<<w[s]+w[e]<<endl;
		//bfs(s,e);
		//cout<<"service is busy..."<<endl;
	}
	return 0;
}
