//草了，最后发现是最短路
//没时间写了 ,坠机了 
#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,q;
int w[1000001]; 
int a[1000001];
int k;
int ans;
struct node{
	int x,y;
};
node fa[1000001];
int find(int x){
	if(fa[x].x==x) return x;
	return fa[x].x =find(fa[x].x);
}
void merge(int x,int y){
	int fx=find(x);
	int fy=find(y);
	if(fx!=fy){
		fa[fx].x=fy;
	}
}
void f(int x,int y){
	if(x==y){
		return;
	}
	ans+=fa[x].y;
	f(fa[x].x,y);
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=0;i<=n;i++){
		fa[i].x=i;
	}
	for(int i=1;i<=n;i++){
		cin>>k;
		int q1,e1,q2,e2;
		cin>>q1>>e1>>q2>>e2;
		merge(q1,q2);
		fa[q1].y=e1;
		fa[q2].y=e2;
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		ans=w[x]+w[y];
		f(x,y);
		cout<<ans<<endl;
	}
	
	
	return 0;
}
