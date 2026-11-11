#include<bits/stdc++.h>
using namespace std;
long long c,t,n,k,dx[5]={0,1,-1,0,0},dy[5]={0,0,0,1,-1};
vector<int> vec[1000005];
vector<int> dot;
void dfs(int xx,int yy){
	
}
bool check(int x){
	int num=0;
	while(x!=0){
		int t=x%2;
		if(t){
			dot.push_back(num);
		}
	}
	int len=dot.size();
	for(int i=1;i<=n;i++){
		
	}
	if(count()){
		
	}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout); 
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<=n-1;i++){
			int u,v;
			cin>>u>>v;
			vec[u].push_back(v);
			vec[v].push_back(u);
		}
		int minn=0x3f3f3f3f;
		for(int i=1;i<=n;i++){
			
		}
	}
	return 0;
}
