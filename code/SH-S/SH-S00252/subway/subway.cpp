#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[500010];//进站时间 
int t[500010][502];//到站台的时间 
vector<int> und[502];//地铁线路 
vector<int> sta[2010];//经过的地铁线路
int k[502];//每条线路的地铁站个数 
int vis[500010];
int cnt=0x3f3f3f3f;
void debug(int x,int y,int z){
	cout<<"from "<<x<<" by  " <<z<<" with  "<<y<<"  \n";
}
void dfs(int now,int end,int ans,int nl){
	//	debug(now,ans,nl);
	if(vis[now]){return;}
	if(end==now){cnt=min(cnt,ans+t[now][nl]); return;}
	if(ans>cnt){return;}
	vis[now]=1;
	for(int i=0;i<sta[now].size();i++){
		if(sta[now][i]==nl){
			for(int j=0;j<und[nl].size();j++){
				dfs(und[nl][j],end,ans,nl);
				//vis[und[nl][j]]=0;
			}
		}
		else{
			for(int j=0;j<und[sta[now][i]].size();j++){
				dfs(und[sta[now][i]][j],end,ans+t[now][sta[now][i]]+t[now][nl],sta[now][i]);
				//vis[und[sta[now][i]][j]]=0;
			}
		}
	}
	vis[now]=0;
}
int main(){
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=0;i<m;i++){
		cin>>w[i];
	}
	for(int i=0;i<n;i++){
		cin>>k[i];
		for(int j=0;j<k[i];j++){
			int tmp1,tmp2;
			cin>>tmp1>>tmp2;
			tmp1-=1;
			t[tmp1][i]=tmp2;
			und[i].push_back(tmp1);
			sta[tmp1].push_back(i);
		}
	}
	for(int i=0;i<q;i++){
		memset(vis,0,sizeof vis);
		cnt=0x3f3f3f3f;
		int x,y;
		cin>>x>>y;
		x-=1,y-=1;
		for(int j=0;j<sta[x].size();j++){
			dfs(x,y,t[x][sta[x][j]],sta[x][j]);
			memset(vis,0,sizeof vis);
		}
		cout<<cnt+w[x]+w[y]<<endl;
	}
	return 0;
}
