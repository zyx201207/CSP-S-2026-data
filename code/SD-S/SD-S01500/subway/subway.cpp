#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<stack>
#include<set>
#include<queue>
#include<map>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<deque>
#include<random>
using namespace std;
#define int long long
typedef pair<int,int> PII;
struct node{
	int sta,w; 
};
int vis[500010]={};
void bfs(){
	queue<int> q;
	q.push(1);
	while(!q.empty()){
		auto op=q.front();
		q.pop();
		/*for(){}
		
		}*/
	}
	
}
int w[500050]={};
vector<node> v[500010]; 
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	} 
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int i=1;i<=k;i++){
			int x,y;
			cin>>x>>y;
			v[i].push_back({x,y});
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		for(int j=1;j<=n;j++){
			
		}
	}
	//fclose(stdin);
	//fclose(stdout);
	return 0;
}

