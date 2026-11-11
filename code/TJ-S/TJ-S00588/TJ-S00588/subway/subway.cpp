#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
typedef pair<int,int> pll;
int c;
int n,m,d;
int q;
long long w[N];
bool st[N];
int dist[N];
struct no{
	int x;
	long long tm;
	bool vis;
}ch[N];
long long b[N];
long long ww[N];
long long idx,h[N],e[N],ne[N];
void add(int x,int y,long long c){
	w[idx]=c;
	e[idx]=y;
	ne[idx]=h[x];
	h[x]=idx++;
}
int D(int x,int y){
	memset(dist,0x3f,sizeof dist);
	dist[x]=0;
	priority_queue<pll,vector<pll>,greater<pll> > heap;
	heap.push({0,x});
	while(heap.size()){
		pll k=heap.top();
		heap.pop();
		int ver=k.second,dise=k.first;
		if(st[ver]) continue;
		st[ver]=true;
		for(int i=h[ver];i!=-1;i=ne[i]){
			int j=e[i];
			if(dist[j]>dise+w[i]){
				dist[j]=dise+w[i];
			  	heap.push({dist[j],j});
			}
		}
	}
	return dist[y];
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	int tt=n;
	while(n--){
		int k;
		cin>>k;
		for(int i=1;i<=k;i++){
			int a,t;
			cin>>a>>t;
			ch[i].x=a;
			b[a]+=t;
			if(n!=tt && ch[i-1].vis){
				add(ch[i-1].x,a,b[ch[i-1].x]);	
			}
			else{
				add(ch[i-1].x,a,0);
				ch[i-1].vis=true;
			}
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
   		cout<<D(x,y)+w[x]+w[y]<<'\n';
	}
	return 0;
}

