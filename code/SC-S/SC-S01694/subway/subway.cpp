#include<bits/stdc++.h>
using namespace std;
const long long L=1e3+5;
const long long R=5e2+5;
int c,n,m,d,q,w[L],k[R],a[R][L],t[R][L];
struct node_7891{
	int c1;
	int wc;
};
vector<node_7891> p[L];
int f[R][R],vvv[R];
int defushi(int x,int y){
	if(x==y){
		
		return 0;
	}
	if(f[x][y]<1e9) return f[x][y];
	for(node_7891 i:p[x]){
		if(!vvv[i.c1]) vvv[i.c1]=1; f[x][y]=min(f[x][y],i.wc+defushi(i.c1,y)); vvv[i.c1]=0;
		
	}
	return f[x][y];
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i]>>a[i][1]>>t[i][1]>>a[i][2]>>t[i][2];
		p[a[i][1]].push_back({a[i][2],t[i][1]+t[i][2]});
		p[a[i][2]].push_back({a[i][1],t[i][1]+t[i][2]});
	}
	for(int i=1;i<=m;i++) f[i][i]=0;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			if(f[i][j]>1e9){ continue;}
			f[i][j]=defushi(i,j);
		}
	}
	while(q--){
		int fuck,man;
		cin>>fuck>>man;
		cout<<defushi(fuck,man)+w[fuck]+w[man]<<endl;
	}
	return 0;
}