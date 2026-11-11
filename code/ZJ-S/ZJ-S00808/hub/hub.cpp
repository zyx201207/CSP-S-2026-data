#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=200005;
vector<int > v[N];
int c,t,in[N],step[N],vis[N],mmax=-1;
void bfs(int asd){
	queue<int > q;
	q.push(asd);
	while(!q.empty()){
		int t=q.front();
		q.pop();
		for(int i=0;i<v[t].size();i++){
			if(!vis[v[t][i]]){
				vis[v[t][i]]=1;
				q.push(v[t][i]);
				step[v[t][i]]=step[t]+1;
				mmax=max(mmax,step[v[t][i]]);
			}
		}
	}
}
void bfs2(int asd,int asd2){
	queue<int > q;
	q.push(asd);
	q.push(asd2);
	while(!q.empty()){
		int t=q.front();
		q.pop();
		for(int i=0;i<v[t].size();i++){
			if(!vis[v[t][i]]){
				vis[v[t][i]]=1;
				q.push(v[t][i]);
				step[v[t][i]]=min(step[t]+1,step[v[t][i]]);
				mmax=max(mmax,step[v[t][i]]);
			}
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		int n,k,mmin=INT_MAX;
		cin>>n>>k;
		for(int i=1;i<=n;i++){
			v[i].clear();
		}
		for(int i=1;i<n;i++){
			int uu,vv;
			cin>>uu>>vv;
			v[uu].push_back(vv);
			v[vv].push_back(uu);
		}
		if(k==1){
			for(int asd=1;asd<=n;asd++){
				memset(vis,0,sizeof(vis));
				mmax=-1;
				for(int i=1;i<=n;i++){
					step[i]=INT_MAX;
				}
				step[asd]=0;
				bfs(asd);
				mmin=min(mmin,mmax);
			}
			cout<<mmin<<endl;
		}else{
			for(int asd=1;asd<=n;asd++){
				for(int asd2=asd+1;asd2<=n;asd2++){
					memset(vis,0,sizeof(vis));
					for(int i=1;i<=n;i++){
						step[i]=INT_MAX;
					}
					mmax=-1;
					step[asd]=0;
					bfs2(asd,asd2);
					mmin=min(mmin,mmax);
				}
			}
			cout<<mmin<<endl;
		}
	}
	
}
