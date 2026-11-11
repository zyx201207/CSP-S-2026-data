#include<bits/stdc++.h>
using namespace std;
int n,m;
int c=0;
int t,d;
const int N=1e5+10;
struct node{
	int to,next;
}a[N];
int k;
int pre[N];
void add(int u,int v){
	k++;
	a[k].to=v;
	a[k].next=pre[u];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
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
