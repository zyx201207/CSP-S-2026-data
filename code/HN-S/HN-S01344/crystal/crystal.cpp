#include<bits/stdc++.h>
using namespace std;

const int N=1e5+10;
struct node{
	int to,next;
}a[N];
int k;
int ma[N];
int pre[N];
int n,m;
void add(int u,int v){
	k++;
	a[k].to=v;
	a[k].next=pre[u];
}
void dfs(int x,int from){
	if(ma[x]==0){
		ma[x]=from;
		for(int i=pre[x];i!=0;i=a[i].next){
			dfs(a[i].to,from);
		}
	}
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
    cin>>n>>m;
    int x,y;
    for(int i=1;i<=m;i++){
    	cin>>x>>y;
    	add(y,x);
	}
	for(int i=n;i>=1;i--){
		dfs(i,i);
	}
	for(int i=1;i<=n;i++){
		cout<<ma[i]<<" ";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
