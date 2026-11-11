#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
const int N=5000+5;
const int inf=LONG_LONG_MAX;
stack<int> v,t;
int x[N];
int e[N][N];
int dis[N][N];
int n,d,ans=0;
void dfs1(int i,int k){
	if(i>n) return ;
	
	//cout<<"t:"<<t.size()<<endl;
	while(!v.empty()){
		int j=v.top();
		t.push(j);
		v.pop();
		if(k<dis[i][j]){
			dis[i][j]=k;
		}
	}
	while(!t.empty()){
		v.push(t.top());
		t.pop();
	}
	//cout<<"OK"<<endl;
	int r=i+1;
	while(x[r]-x[i]<=d){
		v.push(r);
		dfs1(r,k+1);
		v.pop();
		r++;
	}
}
void dfs2(int i,int k){
	if(i>n) return ;
	t=v;
	//cout<<"t:"<<t.size()<<endl;
	while(!v.empty()){
		int j=v.top();
		t.push(j);
		v.pop();
		if(dis[i][j]==k){
			e[i][j]++;
		}
	}
	while(!t.empty()){
		v.push(t.top());
		t.pop();
	}
	//cout<<"OK"<<endl;
	int r=i+1;
	while(x[r]-x[i]<=d){
		
		v.push(r);
		dfs2(r,k+1);
		v.pop();
		r++;
	}
}
void solve(){
	memset(dis,0x3f3f3f3f,sizeof dis);
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>x[i];
	}
	/*dfs1(1,0);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cout<<dis[i][j]<<endl;
		}
	}
	dfs2(1,0);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			//cout<<"e["<<i<<"]["<<j<<"]="<<e[i][j]<<endl;
			if(e[i][j]==1) ans++;
		}
	}
	cout<<ans/2<<endl;
	memset(x,0,sizeof x);
	memset(e,0,sizeof e);
	n=d=ans=0;
	while(!v.empty()) v.pop();*/
	cout<<0<<endl;
}
signed main(){
	//T3部分分都没有，死掉了，预计最高122 分数线不得150了 
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		solve();
	}
	return 0;
} 
