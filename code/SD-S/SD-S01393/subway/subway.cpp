#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
struct node{
	int x,t;
};
vector <node> V[100001];
int c,n,m,d,p,A[1000001],C[1000001],X[1000001],T[1000001],ans;
void dfs(int x,int y){
	queue <int> Q;
	Q.push(x);
	ans+=C[x];
	while(!Q.empty()){
		int h = Q.front();
		Q.pop();
		for(int i = 0;i < V[h].size();i++){
			Q.push(V[h][i].x);
			ans+=V[h][i].t;
			if(V[h][i].x==y){
				return;
			}
		} 
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	cin >> c >> n >> m >> d >> p;
	for(int i = 1;i <= m;i++){
		cin >> C[i];
	}
	for(int i = 1;i <= n;i++){
		int x,v,u;
		cin >> x;
		for(int j = 1;j <= x;j++){
			cin >> A[j] >> T[j]; 
		} 
		for(int j = 1;j <= x;j++){
			if(j==1){
				continue;
			}
			V[A[j]].push_back({A[j-1],T[j]});
			V[A[j-1]].push_back({A[j],T[j-1]});
		}
	}
	for(int i = 1;i <= n;i++){
		int x,y;
		cin >> x >> y;
		ans=0;
		dfs(x,y);
		cout << ans;
	} 
	
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}

