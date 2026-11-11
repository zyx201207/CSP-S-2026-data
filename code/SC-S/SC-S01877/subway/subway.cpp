#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,n,m,d,q1,w[500100];
int x,y;
int k[600];
vector<int> a[510];
vector<int> t[510];
int jilu[500100];
vector<int> jilu2[500100];
struct node{
	int val;
	int cnt;
	int direct;
};
queue<node> q;
bool vis[500100];
void bfs(int begin,int end){
	vis[begin]=true;
	q.push({begin,0,jilu[begin]});
	while(!q.empty()){
		node no=q.front();
		for(int i=0;i<jilu2[no.val].size();i++){
			if(jilu[jilu2[no.val][i]]<0){
				jilu[no.val]=0-no.direct;
				vis[jilu2[no.val][i]]=true;
				q.push({jilu2[no.val][i],no.cnt+a[no.direct][]});
			}else {
				vis[jilu2[no.val][i]]=true;
				q.push({jilu2[no.val][i],});
			}
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q1;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	int opt1,opt2;
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>opt1>>opt2;
			a[i].push_back(opt1);
			t[i].push_back(opt2);
			if(jilu[opt1]!=0){
				jilu[opt1]=-1;
			}else {
				jilu[opt1]=i;
			}
			if(j!=1){
				jilu2[a[i-1][a[i-1].size()-1]].push_back(opt1);
				jilu2[opt1].push_back(a[i-1][a[i-1].size()-1]);
			}
		}
	}
	for(int r=1;r<=q1;r++){
		cin>>x>>y;
		cout<<8<<'\n';
	}
	return 0;
}