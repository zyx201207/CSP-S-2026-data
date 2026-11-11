#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[500005];
map<int,int>at[505];
int tongi[50005];
vector<int>tong;
int ditie(int x,int y){
	int xi,yi;
	for(int i=1;i<=n;i++){
		for(auto j=at[i].begin();j!=at[i].end();j++){
			if(j->first==x){
				xi=i;
			}else if(j->first==y){
				yi=i;
			}
		}
	}
	for(auto i=at[xi].begin();i!=at[xi].end();i++){
		tongi[i->first]++;
	}
	for(auto i=at[yi].begin();i!=at[yi].end();i++){
		tongi[i->first]++;
	}
	for(int i=1;i<=m;i++){
		if(tongi[i]>1){
			tong.push_back(tong[i]);
		}
	}
	if(xi==yi){
		return w[x]+at[xi][x]+at[yi][y]+w[y];
	}else{
		int sum=0;
		for(int i=0;i<tong.size();i++){
			sum=min(sum,w[x]+at[xi][x]+at[xi][tong[i]]+at[yi][tong[i]]+at[yi][y]+w[y]);
		}
	}
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	int k;
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;i++){
			int a,t;
			cin>>a>>t;
			at[i][a]=t;
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		ditie(x,y);
	}
	return 0;
}
