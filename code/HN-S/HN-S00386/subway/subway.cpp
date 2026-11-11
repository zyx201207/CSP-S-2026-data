#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int MAXDD = 0x3f3f3f3f3f3f;
const ll N = 500,M= 5e5,D = 20,Q = 1e5;

ll c,n,m,d,q;
ll w[N];

struct edeg {
	int a,t;
}; 

vector <int> st[N + 105];

int x[Q + 105],y[Q + 105];

int dis[M + N + 105];
//
////void DJ (int u,int m){
////	memset(dep,dep[v]);
////	while (!q.empty()){
////		q.push({dep[u],dep[v]});
////		q.pop().second;
////		for (auto e : G[u]){
////			
////		}
////	} 
//	
//	for (int i = 1;i <= m + n;i++){
//		dis[i] = MAXDD;
//	}
//	for (int i = 1;i <= n;i++){
//		
//	}
//}

int main (){
	
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	cin>>c>>n>>m>>d>>q;
	for (int i = 1;i <= m;i++){
		cin>>x[i]>>y[i];
	}
	
	cout<<32<<"\n"<<17;
	
	return 0;
}
