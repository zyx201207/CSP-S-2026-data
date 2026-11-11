#include<iostream>
#include<cstdio>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;
const int M = 5e5 +3;
int c,n,m,d,q;

int f[M];
void init(){
	for(int i =1;i<=m;i++){
		f[i] =i;
	}
}
int query(int x){
	return f[x]==x?x:f[x] = query(x);
}
void merge(int x,int y){
	int rx = query(x),ry = query(y);
	if(rx != ry){
		f[rx] = ry;
	}
}
struct Sp{
	int w;
	int t;
	vector<int> r;//road
}sp[M];
void fopen(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
}
void solve(){
	int b,e;cin >>b>>e;
	cerr<<"WW";
	//if(query(b) == query(e)){
	cout<<sp[b].w+sp[e].w+sp[e].t+sp[b].t<<"\n";
	//}
	
}
int main(){
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	fopen();
	cin >> c>>n>>m>>d>>q;
	
	init();
	for(int i=1;i<=m;i++){
		cin >> sp[i].w;
	}

	int pre = 0;
	int k;
	int s,t;
	for(int i =1;i<=n;i++){
		cin >>k;
		for(int j =1;j<=k;j++){
			
			cin >>s >>t;
			sp[s].t = t;
			//if (j!=1)merge(s,pre);
			pre = s;
		}
		
	}
	while(q--){
		//solve();
		int b,e;cin >>b>>e;
		cout<<sp[b].w+sp[e].w+sp[e].t+sp[b].t<<"\n";
	}
	return 0;
}
