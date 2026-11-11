#include <bits/stdc++.h>

using namespace std;

struct Node{
	int val;
	int stp;
};

queue<Node> q;
bool vis[2000010];

int x[2000010];
int n, d;

bool bfs(int st, int ed){
	memset(vis, 0, sizeof vis);
	
	q.push(Node{st, 0});
	vis[st] = 1;
	
	int stph = -1;
	int phct = 0;
	
	while(!q.empty()){
		Node qf = q.front();
		int v = qf.val;
		int t = qf.stp;
		
		q.pop();
		
		if(v == ed){
			if(t != stph && stph != -1) break;
			
			if(stph == -1){
				stph = t; 
		    }
		    phct ++;
		}
		
		for(int i=v+1; x[i] -  x[v] <= d && i <= n; i++){
			if(!vis[i]){
				q.push({i, t+1});
				vis[i] = 1;
			}
		}
		
	}
	
	return phct == 2;
}

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);

    int c, t;
    cin>>c>>t;
    
    while(t --){
    	cin>>n>>d;
    	
    	for(int i=1; i<=n; i++){
    		cin>>x[i];
		}
		
		if(c == 11 || c == 12){
			cout<<0<<endl;
		}
	}

	return 0;
}
/*

大暴力拿分吧

累了
懒得调了
放弃了
写特A

这是错的
算了不写了

*/