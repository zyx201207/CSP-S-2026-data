#include<bits/stdc++.h>
using namespace std;
struct paltfalm{
	int a,t;
}x[505][505];
int tn=0;
int dfs(int s,int e){
	if(s==e){
		return w[e-1];
	}
	return dfs(,e)+
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,m,n,d,q,t;
	cin>>c>>m>>n>>d>>q;
	int w[m+1],k[501];
	for(int i=0;i<m;i++){
		cin>>w[i];
	}
	bool s=true;
	for(int i=0;i<n;i++){
		cin>>k[i];
		if(k[i]>2){
			s=false;
		}
		for(int j=0;j<k[i];j++){
			cin>>x[i][j].a>>x[i][j].t;
		}
	}
	for(int i=0;i<q;i++){
		int x,y;
		cin>>x>>y;
		if(s){
			cout<<dfs(x,y)<<endl;
		}
	}
	return 0;
}