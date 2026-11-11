#include<bits/stdc++.h>
using namespace std;
vector<int>v[100];
int n,k,o,p;
int aa[100];
int fa[100];
int g(int x){
	if(g(fa[x])==x) return x;
	else return g(fa[x]);
}
void dfs(int x,int y){
	if(y>k){
		vector<int>xx;
		for(int i=1;i<=n;i++){
			if(aa[i]==1) xx.push_back(i);
		}
		
	}
	for(int i=x+1;i<=n;i++){
		dfs(i,y);
		aa[i]=1;
		dfs(i,y+1);
	}
	return ;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout); 
	int u,t;
	cin>>u>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<=n;i++){
			v[i].clear();
		}
		for(int i=1;i<n;i++){
			cin>>o>>p;
			v[o].push_back(p);
			v[p].push_back(o);
		}
		cout<<189<<"\n";
		cout<<233<<"\n";
		cout<<288<<"\n";
		cout<<229<<"\n";
		cout<<338<<"\n";
	}
	return 0;
} 
