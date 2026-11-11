#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
const int M=3e5+5;
int a[N],b[M],vis[M];
int m,n;
struct node{
	int next,to;	
};
node edge[M*2];
int vex[M],ei=1;
void add(int u,int v){
	edge[ei].next=vex[u];
	edge[ei].to=v;
	vex[u]=ei++;
}
void f(int x){
	int idx=vex[x];
	while(idx!=-1){
		f(edge[idx].to);
		b[x]+=b[edge[idx].to];
		idx=edge[idx].next;
	}
	return;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	memset(vex,-1,sizeof vex);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		vis[a[i]]=i;
		b[a[i]]++;
	}
	for(int i=1;i<=m;i++){
		add(a[vis[i]+1],i);
	}
	f(a[n]);
	for(int i=1;i<m;i++){
		cout<<b[i]<<" ";
	}
	cout<<b[m];
	return 0;
}