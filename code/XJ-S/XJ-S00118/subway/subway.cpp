#include<bits/stdc++.h>
using namespace std;
vector<int> v[10005];
int c,n,m,d,q;
int w[10005];
struct node{
	int a,t;
	friend bool operator < (const node &a,const node &b){
		return a.t<b.t;
	}
}k[100005];
int k1;
vector<int> fa;
int find(int x){
	if(fa[x]==x){
		return x;
	}
	fa[x]=find(fa[x]);
	return fa[x];
}
void merge(int x,int y){
	fa[find(x)]=find(y);
}
void solve(int x){
	for(int i=1;i<=k1;i++){
		int u=find(x),v=find(k[i].a);
		if(u!=v){
			merge(x,k[i].a);
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	for(int i=1;i<=n;i++){
		cin>>k1;
		for(int j=1;j<=k1;j++){
			cin>>k[j].a>>k[j].t;
			//k[j].aµã
			//k[j].t±ßÈ¨ 
		}
		solve(k[i].a);
	}
	return 0;
}
