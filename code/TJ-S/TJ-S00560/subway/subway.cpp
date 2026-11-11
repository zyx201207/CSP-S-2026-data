#include<bits/stdc++.h> 
using namespace std;
const int N=5e5;
int c,n,m,d,q,w[N],BEGIN,END;
vector <pair<int,int> > e[2*N];
void bfs(int x,int y){
	queue<int>q;
	q.push(x);
	while(q.size()){
		int op=q.front();
		for(pair<int,int> u:e[op]){
			if(op==y)continue;
		}
	}
}
int main(){
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int a[N],k,t[N];
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[i]>>t[i];
		}
		for(int x=1;x<=k;x++){
			for(int y=1;y<=k;y++){
				if(x!=y){
					e[a[x]].push_back({a[y],t[x]+t[y]});
					e[a[y]].push_back({a[x],t[x]+t[y]});
				}
			}
		}
	}
	for(int i=1;i<=q;i++){
		cin>>BEGIN>>END;
		bfs(BEGIN,END);
	}
	return 0;
}
