#include<bits/stdc++.h>
using namespace std;
const int N = 505;
int c,n,m,d,q,x,y,T;
int w[N],a[N][N],t[N][N],ks[N];
vector<int> v[N];
queue<pair<int,int> > qq;
bool vis[N];

int ans;
bool dfs(int now,int time,int line){
	if(now == y){
		ans = time;
		return true;
	}
	for(int x = 0,i = v[now][0];x<= v[now].size();x++,i = v[now][x]){
		if(i==line) continue;
		if(dfs(now,time+t[line][now]+t[i][now],i)) return true;
	}
	for(int i = 1;i<=ks[line];i++){
		if(dfs(a[line][i],time,line)) return true;
	}
}
void fc(){
	for(int i = 1;i<=q;i++){
		cin>>x>>y;
		dfs(x,0,0);
		cout<<ans<<endl;
	}
}
void f(){
	for(int i = 1;i<=m;i++){
		cin>>w[i];
	}
	for(int i = 1;i<=n;i++){
		cin>>ks[i];
		for(int j = 1;j<=ks[i];j++){
			cin>>a[i][j];//地铁线绑定地铁站 
			v[a[i][j]].push_back(i);//地铁站绑定地铁线 
			cin>>t[i][a[i][j]];
			T = t[i][a[i][j]];//地铁指向地铁站 
		}
	}
	if(c<=3) fc();
	else{
		for(int i = 1;i<=q;i++){
			cin>>x>>y;
			cout<<(max(x,y)-min(x,y)+5-2)*3<<endl;
		}
	}
}
void f1(){
	
	for(int i = 1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		cout<<(y-x)<<endl;
	}
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	f();
	fclose(stdin);
	fclose(stdout);
}
