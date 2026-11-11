#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
vector<int> linju[1010];
vector<int> w,pre[1010];
int t[510][5010];
int k;
int f[1010];
queue<int> b1;
int vis[1010];
vector<int> val[1010];
void bfs(int end){
	while(!b1.empty()){
		int now=b1.front();
		if(now==end){
			break;
		}
		b1.pop();
		for (int i=0;i<linju[now].size();i++){
			if(!vis[linju[now][i]]){
				f[linju[now][i]]=now; 
				b1.push(linju[now][i]);
				vis[linju[now][i]]=1;
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	int d;
	w.push_back(0);
	for (int i=1;i<=m;i++){
		cin>>d;
		w.push_back(d);
	}
	int a1,t1,l=0;
	for (int i=1;i<=n;i++){
		cin>>k;
		for (int j=1;j<=k;j++){
			cin>>a1>>t1;
			if(j!=1){
				linju[l].push_back(a1);
				linju[a1].push_back(l);
			}
			val[a1].push_back(i);
			t[i][a1]=t1;
			l=a1;
		}
	}
	int start,end,ans=0;
	for (int i=1;i<=q;i++){
		cin>>start>>end;
		ans=w[start]+w[end]+t[val[start][0]][start]+t[val[end][0]][end];
		memset(vis,0,sizeof(vis));
		vis[start]=1;
		b1.push(start);
		bfs(end);
		int o=end;
		while(o!=start){
			if(val[f[o]].size()==1){
				o=f[o];
			}else{
				if(val[f[f[o]]][0]==val[o][0]){
					o=f[o];
				}else{
					ans+=(t[val[f[o]][0]][f[o]]+t[val[o][0]][f[o]]);
				}
			}
		}
		cout<<ans;
	}
	return 0;
}
