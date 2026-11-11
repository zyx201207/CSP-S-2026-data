#include<bits/stdc++.h> 
using namespace std;
int c,n,m,d,q;
int f[1000000];
struct node{
	int v,w;
};
struct node2{
	int a,t;
}S[1000000];
bool cmp(node2 a,node2 b){
	return a.t<b.t;
}
int hui[1000000];
node2 vis[1000000];
vector<node>N[1000000];
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >q;
int w[1000000];
int find(int x){
	if(f[x]==x)return x;
	return f[x]=find(f[x]);
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>t[i];
	}
	int k;
	for(int i=1;i<=n;i++){
		f[i]=i;
	}
	int cnt=1;
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>S[j].a>>S[j].t;
			int fx=find(S[j-1].a);
			int fy=find(S[j].a);
			if(fx!=fy)f[fx]=fy;
			hui[S[j].a]++;
			if(hui[S[j].a>=2]){
				vis[cnt++].a=S[j].a;
				vis[cnt++].t=S[j].t;
			}
		}
	}
	
	return 0;
}
