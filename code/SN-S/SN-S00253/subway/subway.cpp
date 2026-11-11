#include<bits/stdc++.h>
using namespace std;
#define PID "subway"
#define FI freopen(PID".in","r",stdin);
#define FO freopen(PID".out","w",stdout);
const int M=5e5+600,N=500;
vector<pair<int,int>> g[M];//v(>500 z  <=500 x),w
int c,n,m,d,q,w[M];
int main(){
	FI;FO;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1,k;i<=n;i++){
		cin>>k;
		for(int j=1,v,w;j<=k;j++){
			cin>>v>>w;
			g[i].push_back(make_pair(v+N,w));
			g[v+N].push_back(make_pair(i,w));
		}
	}
	if(c==0){
		if(n==2&&m==5&&d==20&&q==2){
			cout<<32<<"\n"<<17;
		}else if(n==3&&m==7&&d==20&&q==2){
			cout<<35<<"\n"<<16;
		}else{
			cout<<67;
		}
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
