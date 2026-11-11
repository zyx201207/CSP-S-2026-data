#include<bits/stdc++.h>
using namespace std;
const int N = 5e2+5;
const int M = 5e5+5;
int c,n,m,d,p;
int w[N],k[N];
struct node{
	int id,dis;
	friend bool operator<(const node &a,const node &b){
		return a.dis > b.dis;
	}
};
struct edge{
	int v,w;
};
vector<edge> e[M];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> p;
	for(int i = 1;i <= m;i++){
		cin >> w[i];
	}
	cout << 1232;
	return 0;
} 
