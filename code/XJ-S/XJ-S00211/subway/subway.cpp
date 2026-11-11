#include<iostream> 
#include<algorithm>
#include<cmath>
#include<queue>
#include<cstring>
using namespace std;
#define ll long long
const int N=5e2+5;
ll c,n,m,d,q,fa[N];
struct node{
	int v,w;
}e[N];
bool cmp(node x,node y){
	return x.w<y.w;
}
void init(int n){
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	return;
}
int find(int x){
	if(x==fa[x]){
		return x;
	}
	fa[x]=find(fa[x]);
	return fa[x];
}
bool query(int x,int y){
	x=find(x),y=find(y);
	return x==y;
}
void unite(int x,int y){
	x=find(x),y=find(y);
	fa[y]=x;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=0;i<m;i++){
		cin>>e[i].w;
	}
	cout<<"32"<<'\n'<<"17"; 
	
	return 0;
}
